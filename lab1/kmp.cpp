#include "kmp.h"

int main() {
    string substring;
    string line;
    cout << "string: ";
    cin  >> line;
    cout << endl;
    cout << "substring: ";
    cin  >> substring;
    cout << endl;
    cout << algoritmKmp(line, substring) << endl;

    return 0;
}
