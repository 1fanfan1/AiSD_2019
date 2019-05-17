#include "functions_step1.h"

int main() {
    AxoKarasik axoKarasik;
    string T;
    cout << "Input text: "; 
    cin >> T;
    cout << "Input number of patterns: ";
    int N;
    cin >> N;
    cout << "Input patterns:" << endl;
    while (N--){
        string str;
        cin >> str;
        axoKarasik.addPattern(str);
    }
 
    cout << axoKarasik.searchString(T);
    return 0;
}
