#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector <int> prefix_function(string form){
    int n = form.size();
    vector <int> p(n);
    for (int i = 1, j = 0; i < n; i++){
        while (j > 0 && form[i] != form[j])
            j = p[j - 1];
        if (form[i] == form[j])
            j++;
        p[i] = j;
    }

    return p;
}

string algoritmKmp(string text, string substring){
    vector <int> P = prefix_function(substring + "|" + text);
    int n = substring.size();
    int m = text.size();
    string out;

    bool flag = false;
    for (int i = n + 1; i < n + m + 1; i++)
        if (P[i] == n){
            if (flag){
                cout << ",";
                out.append(",");
            }
            cout << (i - (n + 1) - (n - 1));
            out.append(std::to_string(i - (n + 1) - (n - 1)));
            flag = true;
        }
    if (!flag){
        cout << -1 << endl;
        out.append("-1");
    }
    return out;
}

int main() {
    string substring = "ab";
    string line = "ababkabbab";
    cout << "test 1" << endl;
    cout << "string: " << line << endl;
    cout << "substring: " << substring << endl;
    assert(algoritmKmp(line, substring) == "0,2,5,8");
    cout << endl << endl;
    substring.clear();
    line.clear();
    substring = "abcef";
    line = "abcd";
    cout << "test 2" << endl;
    cout << "string: " << line << endl;
    cout << "substring: " << substring << endl;
    assert(algoritmKmp(line, substring) == "-1");

    return 0;
}
