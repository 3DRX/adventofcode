#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using std::vector;

void input(vector<int>* LI);
int  getAns(vector<int>* LI);

int main(void)
{
    vector<int>* LI = new vector<int>;
    input(LI);
    std::cout << getAns(LI) << std::endl;
    return 0;
}

void input(vector<int>* LI)
{
    int valueOfElf = 0;
    while (1) {
        char iptBuf[10];
        gets(iptBuf);
        if (strcmp(iptBuf, "") == 0) {
            LI->push_back(valueOfElf);
            valueOfElf = 0;
        }
        else {
            int ipt = atoi(iptBuf);
            if (ipt == -1) {
                break;
            }
            valueOfElf += ipt;
        }
    }
}

int getAns(vector<int>* LI)
{
    return *std::max_element(LI->begin(), LI->end());
}
