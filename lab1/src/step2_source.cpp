#include "functions.h"

int main() {
    string line;
    string substring; 
    cout << "string: ";
    cin  >> line;
    cout << "substring: ";
    cin  >> substring;
    cout << "padding: " << isCircle(substring, line) << endl;
    return 0;
}
