#include <iostream>
#include <string>
// #include <limits>

using namespace std;

struct Engineer {
    string type{};
    int proficiencyLevel{};
    string* skills{};
    int numsSkills{};

    ~Engineer() {
        if (skills)
            delete[] skills;
        skills = nullptr;
    }
};

void inputEngineer(Engineer* engineerPtr);
void outputEngineer(const Engineer* engineerPtr);

int main() {
    const int NUMS_ENGINEERS{2};

    Engineer* listEngineers{new Engineer[NUMS_ENGINEERS]};
    for (int i{0}; i < NUMS_ENGINEERS; ++i) // populate the list
        inputEngineer(&listEngineers[i]);

    for (int i{0}; i < NUMS_ENGINEERS; ++i)
        outputEngineer(&listEngineers[i]); // output

    delete[] listEngineers;
    return 0;
}

void inputEngineer(Engineer* engineerPtr) {
    int inputNumSkills{};
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
    cout << "How many skills: ";
    cin >> inputNumSkills;
    cin.ignore();
    engineerPtr->numsSkills = inputNumSkills;
    engineerPtr->skills = new string[inputNumSkills];
    cout << "List valuable skills\n";
    for (int i{0}; i < inputNumSkills; ++i) {
        cout << "\tSkill # " << i + 1 << ": ";
        getline(cin, engineerPtr->skills[i]);
    }
    // cin.ignore();
}

void outputEngineer(const Engineer* engineerPtr) {
    // static int counter{1};
    // cout << "Engineer #" << counter << '\n'
    cout << '\n';
    cout << "Type: " << engineerPtr->type << '\n'
         << "Proficiency level: " << engineerPtr->proficiencyLevel << '\n';
    for (int i{0}; i < engineerPtr->numsSkills; ++i) {
        cout << "Skill #" << i + 1 << ": ";
        cout << engineerPtr->skills[i] << '\n';
    }
    // ++counter;
    cout << "----------------";
}
