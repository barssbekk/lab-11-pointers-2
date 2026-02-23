#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Engineer {
    string type{};
    int proficiencyLevel{};
    int* skills{};

    ~Engineer() {
        if (skills)
            delete[] skills;
        skills = nullptr;
    }
};

void inputEngineer(Engineer* engineerPtr, int size);
void outputEngineer(const Engineer* engineerPtr);

int main() {
    const int NUMS_ENGINEERS{5};

    Engineer* listEngineers{new Engineer[NUMS_ENGINEERS]};
    for (int i{0}; i < NUMS_ENGINEERS; ++i) // populate the list
        inputEngineer(&listEngineers[i], NUMS_ENGINEERS);

    for (int i{0}; i < NUMS_ENGINEERS; ++i)
        outputEngineer(&listEngineers[i]); // output

    delete[] listEngineers;
    return 0;
}

void inputEngineer(Engineer* engineerPtr, const int size) {
    static int counter{1};
    cout << "Engineer Data #" << counter << '\n'
         << "Engineer type: ";
    getline(cin, engineerPtr->type);

    cout << "Proficiency level (0-5): ";
    cin >> engineerPtr->proficiencyLevel;
    while (engineerPtr->proficiencyLevel < 0 || engineerPtr->proficiencyLevel > 5) {
        cout << "Please enter (0-5): ";
        cin >> engineerPtr->proficiencyLevel;
    }
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // ADD: *skills
    Engineer* skills{new Engineer[size]};
    for (int i{0}; i < size; ++i) {
        cout << "Skill # " << i + 1 << ':';
        cin >> engineerPtr->skills[i];
    }
    cin.ignore();
    ++counter;
    cout << '\n';
}

void outputEngineer(const Engineer* engineerPtr) {
    static int counter{1};
    cout << "Engineer #" << counter << '\n'
         << "\tType: " << engineerPtr->type << '\n'
         << "\tProficiency level: " << engineerPtr->proficiencyLevel;
    ++counter;
    cout << '\n';
}
