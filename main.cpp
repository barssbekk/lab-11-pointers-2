#include <iostream>
#include <string>

using namespace std;

struct Engineer {
    string type;
    int proficiencyLevel;
    int* skills;

    ~Engineer() {
        if (skills)
            delete[] skills;
        skills = nullptr;
    }
};

int main() {

    return 0;
}