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
const void outputEngineer(Engineer* engineerPtr);

int main() {
    const int NUMS_ENGINEERS{5};

    Engineer* listEngineers{new Engineer[NUMS_ENGINEERS]};
    inputEngineer(listEngineers);

    delete[] listEngineers;
    return 0;
}

void inputEngineer(Engineer* engineerPtr) {
    cout << "Engineer type: ";
    getline(cin, engineerPtr->type);
}

const void outputEngineer(Engineer* engineerPtr) {

}
