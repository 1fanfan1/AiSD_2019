#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct FlagEnd{
    bool flag;
    vector <int> patterNumber;
};

struct Vertex{
    FlagEnd flagEnd;
    map <char, int> next;
    map <char, int> autoMove;
    int suffixLink;
    int parent;
    char symbol;

    Vertex(int parent,char symbol) {
        this->flagEnd.flag = false;
        this->suffixLink  = -1;
        this->parent       = parent;
        this->symbol       = symbol;
    }
};

class AxoKarasikWithJoker{
public:
    AxoKarasikWithJoker(string strWithJoker){
        borh.push_back(Vertex(0,0));
        count = 1;
        this->strWithJoker = strWithJoker;
    }

    void addPattern(const string &pattern,int index){
        int curVer = 0; //стоим в корне
        this->patterns.push_back(pair <string, int>(pattern, index));
        for (char symbol:pattern){
            if (borh[curVer].next.find(symbol) == borh[curVer].next.end()){
                borh.push_back(Vertex(curVer,symbol));
                borh[curVer].next[symbol] = count++;
            }
            curVer = borh[curVer].next[symbol];
        }
        borh[curVer].flagEnd.flag = true;
        borh[curVer].flagEnd.patterNumber.push_back(this->patterns.size());
    }

    string searchString(const string& str){
        vector <int> C(str.size(), 0);
        int curVer = 0;
	string out = "";
        for (int i = 0;i < str.size(); i++){
            curVer = getAutoMove(curVer, str[i]);
            for (int ver = curVer; ver != 0; ver = getSuffixLink(ver)){
                if (borh[ver].flagEnd.flag){
                    for (int index = 0; index < borh[ver].flagEnd.patterNumber.size(); index++) {
                        int patterNumber = borh[ver].flagEnd.patterNumber[index];
                        int position = i - patterns[patterNumber - 1].first.size() + 1;
                        if (position - patterns[patterNumber - 1].second >= 0) {
                            if (patterNumber == 1) {
                                C[position - patterns[patterNumber - 1].second]++;
                            }
                            else if (C[position - patterns[patterNumber - 1].second] != 0) {
                                C[position - patterns[patterNumber - 1].second]++;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < C.size(); i++){
            if (C[i] == patterns.size() && ((i + strWithJoker.size() <= C.size()))){
                out.append(std::to_string(i + 1)); 
		out.append("\n");
            }
        }
        return out;
    }


private:
    vector <Vertex> borh;
    vector <pair <string, int>> patterns;
    string strWithJoker;
    int count;

    int getSuffixLink(int vertex){
        
        if (borh[vertex].suffixLink == -1)
            if (vertex == 0 || borh[vertex].parent == 0)
                borh[vertex].suffixLink = 0;
            else
                borh[vertex].suffixLink = getAutoMove(getSuffixLink(borh[vertex].parent), borh[vertex].symbol);
        return borh[vertex].suffixLink;
    }

    int getAutoMove(int vertex, char symbol){
        
        if (borh[vertex].autoMove.find(symbol) == borh[vertex].autoMove.end())
            if(borh[vertex].next.find(symbol) != borh[vertex].next.end())
                borh[vertex].autoMove[symbol] = borh[vertex].next[symbol];
            else
                borh[vertex].autoMove[symbol] = ((vertex == 0) ? 0 : getAutoMove(getSuffixLink(vertex),symbol));
        
        return borh[vertex].autoMove[symbol];
    }

};
