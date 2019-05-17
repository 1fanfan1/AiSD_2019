#include "functions_step2.h"

int main() {
    string T;
    string pattern;
    char joker;
    cout << "Input text: "; 
    cin >> T;
    cout << "Input pattern: ";
    cin >> pattern;
    cout << "Input joker sybmol: ";
    cin >> joker;

    AxoKarasikWithJoker axoKarasik(pattern);
    string additionStr = "";
    for (int i = 0; i < pattern.size(); i++){
        if (pattern[i] != joker)
            additionStr = additionStr + pattern[i];
        else
            if (additionStr.size() != 0) {
                axoKarasik.addPattern(additionStr, i - additionStr.size());
                additionStr = "";
            }
    }
    if (additionStr.size() != 0)
        axoKarasik.addPattern(additionStr, pattern.size() - additionStr.size());

    cout << axoKarasik.searchString(T);
    return 0;
}
