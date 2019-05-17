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
                out.append(",");
            }
            out.append(std::to_string(i - (n + 1) - (n - 1)));
            flag = true;
        }
    if (!flag){
        out.append("-1");
    }
    return out;
}

int isCircle(string A, string B){
    if (A.size() != B.size())
	return -1;
 
    int index = prefix_function(A + "|" + B).back(); 

    if (index == A.size()) 
        return 0;
    return index + prefix_function(B + "|" + A).back() == A.size() ? index: -1;
}
