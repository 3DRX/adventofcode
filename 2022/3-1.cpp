#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::vector;

void input(vector<string>* LI);
int  getRes(vector<string>* LI);
char commonChar(string a, string b);

int main(void)
{
    vector<string>* LI = new vector<string>;
    input(LI);
    std::cout << getRes(LI) << std::endl;
    return 0;
}

void input(vector<string>* LI)
{
    while (1) {
        string inputStr;
        std::cin >> inputStr;
        if (inputStr == "") {
            return;
        }
        LI->push_back(inputStr);
    }
}

int getRes(vector<string>* LI)
{
    int res = 0;
    for (int i = 0; i < LI->size(); i++) {
        int    strSize = LI->at(i).size();
        string left = LI->at(i).substr(0, strSize / 2);
        string right = LI->at(i).substr(strSize / 2);
        char   common = commonChar(left, right);
        if (common >= 'a' && common <= 'z') {
            res += common - 'a' + 1;
        }
        else {
            res += common - 'A' + 27;
        }
    }
    return res;
}

char commonChar(string a, string b)
{
    std::unordered_set<char> SET;
    for (int i = 0; i < a.size(); i++) {
        SET.insert(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        if (SET.count(b[i]) > 0) {
            return b[i];
        }
    }
    return '\0';
}
