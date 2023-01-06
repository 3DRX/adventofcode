#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::vector;

void input(vector<string>* LI);
int  getRes(vector<string>* LI);
char commonChar(string a, string b, string c);

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
    for (int i = 0; i < LI->size(); i += 3) {
        std::cout << "i= " << i << std::endl;
        std::cout << LI->at(i) << std::endl;
        char common = commonChar(
                LI->at(i), 
                LI->at(i + 1), 
                LI->at(i + 2)
                );
        if (common >= 'a' && common <= 'z') {
            res += common - 'a' + 1;
            std::cout<<"res: "<<res<<std::endl;
        }
        else {
            res += common - 'A' + 27;
            std::cout<<"res: "<<res<<std::endl;
        }
    }
    return res;
}

char commonChar(string a, string b, string c)
{
    std::unordered_set<char> SET1;
    std::unordered_set<char> SET2;
    for (int i = 0; i < a.size(); i++) {
        SET1.insert(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        SET2.insert(b[i]);
    }
    for (int i = 0; i < c.size(); i++) {
        if (SET1.count(c[i]) > 0 && SET2.count(c[i]) > 0) {
            return c[i];
        }
    }
    std::cout<<"???"<<std::endl;
    return '\0';
}
