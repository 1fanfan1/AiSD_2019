#include "functions.h"

int main() {
    string substring;
    string line;
    cout << "string: ";
    cin  >> line;
    cout << "substring: ";
    cin  >> substring;
    cout << algoritmKmp(line, substring) << endl;

    return 0;
}
