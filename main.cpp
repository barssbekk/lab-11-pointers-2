#include <iostream>
#include <string>

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

void inputEngineer(Engineer* engineerPtr);
void outputEngineer(const Engineer* engineerPtr);

int main() {
    const int NUMS_ENGINEERS{5};

    Engineer* listEngineers{new Engineer[NUMS_ENGINEERS]};
    for (int i{0}; i < NUMS_ENGINEERS; ++i)
        inputEngineer(&listEngineers[i]);

    for (int i{0}; i < NUMS_ENGINEERS; ++i)
        outputEngineer(&listEngineers[i]);

    delete[] listEngineers;
    return 0;
}

void inputEngineer(Engineer* engineerPtr) {
    cout << "Engineer type: ";
    getline(cin, engineerPtr->type);

    cout << "Proficiency level (0-5): ";
    cin >> engineerPtr->proficiencyLevel;
    while (engineerPtr->proficiencyLevel < 0 || engineerPtr->proficiencyLevel > 5) {
        cout << "Please enter (0-5): ";
        cin >> engineerPtr->proficiencyLevel;
    }
    cin.ignore();

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
