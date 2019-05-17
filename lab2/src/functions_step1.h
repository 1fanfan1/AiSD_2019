#include <map>
#include <vector>
#include <iostream>

using namespace std;

struct FlagEnd{
    bool flag;
    int patterNumber;
};

struct Vertex{
    FlagEnd         flagEnd;
    map <char, int> next;
    map <char, int> autoMove;
    int             suffixLink;
    int             parent;
    char            symbol;

    Vertex (int parent, char symbol) {

        this->flagEnd.flag = false;
        this->flagEnd.patterNumber = 0;
        this->suffixLink = -1;
        this->parent = parent;
        this->symbol = symbol;
    }
};

class AxoKarasik
{
public:
    AxoKarasik(){

        borh.push_back(Vertex(0, 0));
        count = 1;
    }

    void addPattern(const string &pattern){

        int curVer = 0; //стоим в корне
        this->pattern.push_back(pattern);
        for (char symbol:pattern){
            if (borh[curVer].next.find(symbol) == borh[curVer].next.end()){
                borh.push_back(Vertex(curVer, symbol));
                borh[curVer].next[symbol] = count++;
            }
            curVer = borh[curVer].next[symbol];
        }
        borh[curVer].flagEnd.flag = true;
        borh[curVer].flagEnd.patterNumber = this->pattern.size();
    }

    string searchString(const string& str){
	
    string out = "";

        int curVer = 0;
        for (int i = 0; i < str.size(); i++){
            curVer = getAutoMove(curVer, str[i]);
            for (int ver = curVer; ver != 0; ver = getSuffixLink(ver)){
                if (borh[ver].flagEnd.flag){
                    int patternNumber = borh[ver].flagEnd.patterNumber;
                    int position = i - pattern[patternNumber - 1].size() + 2;
                    out.append(std::to_string(position));
		    out.append(" ");
		    out.append(std::to_string(patternNumber));
		    out.append("\n");
                }
            }
        }
        return out;
    }


private:
    vector<Vertex> borh;
    vector<string> pattern;
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
            if (borh[vertex].next.find(symbol) != borh[vertex].next.end())
                borh[vertex].autoMove[symbol] = borh[vertex].next[symbol];
            else
                borh[vertex].autoMove[symbol] = ((vertex == 0) ? 0 : getAutoMove(getSuffixLink(vertex), symbol));

        return borh[vertex].autoMove[symbol];
    }
};

