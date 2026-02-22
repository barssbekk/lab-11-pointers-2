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

int main() {
    const int NUMS_ENGINEERS{5};

    Engineer* me{new Engineer[NUMS_ENGINEERS]};

    delete[] me;
    return 0;
}

void intputEngineer(Engineer* engineerPtr) {
    cout << "Engineer type: ";
    getline(cin, engineerPtr->type);
}