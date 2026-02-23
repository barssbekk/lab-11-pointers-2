#include <iostream>
#include <string>
// #include <limits>

using namespace std;

struct Engineer {
    string type{};
    int proficiencyLevel{};
    string* skills{};

    ~Engineer() {
        if (skills)
            delete[] skills;
        skills = nullptr;
    }
};

void inputEngineer(Engineer* engineerPtr, int size, int numSkills);
void outputEngineer(const Engineer* engineerPtr, int numSkills);

int main() {
    const int NUMS_ENGINEERS{2};
    constexpr int NUMS_SKILLS{3};

    Engineer* listEngineers{new Engineer[NUMS_ENGINEERS]};
    for (int i{0}; i < NUMS_ENGINEERS; ++i) // populate the list
        inputEngineer(&listEngineers[i], NUMS_ENGINEERS, NUMS_SKILLS);

    for (int i{0}; i < NUMS_ENGINEERS; ++i)
        outputEngineer(&listEngineers[i], NUMS_SKILLS); // output

    delete[] listEngineers;
    return 0;
}

void inputEngineer(Engineer* engineerPtr, const int size, const int numSkills) {
    cout << "Engineer Info\n"
         << "Engineer type: ";
    getline(cin, engineerPtr->type);

    cout << "Proficiency level (0-5): ";
    cin >> engineerPtr->proficiencyLevel;
    while (engineerPtr->proficiencyLevel < 0 || engineerPtr->proficiencyLevel > 5) {
        cout << "Please enter (0-5): ";
        cin >> engineerPtr->proficiencyLevel;
    }
    cin.ignore();
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // ADD: *skills
    engineerPtr->skills = new string[size];
    cout << "List 3 valuable skills\n";
    for (int i{0}; i < numSkills; ++i) {
        cout << "\tSkill # " << i + 1 << ": ";
        getline(cin, engineerPtr->skills[i]);
    }
    // cin.ignore();
}

void outputEngineer(const Engineer* engineerPtr, const int numSkills) {
    // static int counter{1};
    // cout << "Engineer #" << counter << '\n'
    cout << '\n';
    cout << "Type: " << engineerPtr->type << '\n'
         << "Proficiency level: " << engineerPtr->proficiencyLevel << '\n';
    for (int i{0}; i < numSkills; ++i) {
        cout << "Skill #" << i + 1 << ": ";
        cout << engineerPtr->skills[i] << '\n';
    }
    // ++counter;
    cout << "----------------";
}
