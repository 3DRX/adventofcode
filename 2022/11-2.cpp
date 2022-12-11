#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Monkey {
    long long         inspectTimes;
    long long         index;
    long long         testNum;
    long long         trueDest;
    long long         falseDest;
    vector<long long> items;
    struct operation {
        // nums are set to -1 to represent old
        long long num1;
        long long num2;
        char      operatorr;
    } oper;
};

void      inputMonkeys(vector<Monkey>* L);
long long ans(vector<Monkey>* L, long long magicNumber);
long long getMagicNumber(vector<Monkey>* L);

int main(void)
{
    vector<Monkey> L;
    inputMonkeys(&L);
    std::cout << ans(&L, getMagicNumber(&L)) << std::endl;
    return 0;
}

void inputMonkeys(vector<Monkey>* L)
{
    string iptLine;
    while (1) {
        Monkey newMonkey;
        newMonkey.inspectTimes = 0;
        std::getline(std::cin, iptLine);
        if (iptLine[0] == 'E') {
            break;
        }
        else if (iptLine[0] == 'M') {
            newMonkey.index = iptLine[iptLine.size() - 2] - '0';
            // get startingItems
            std::getline(std::cin, iptLine);
            iptLine = iptLine.substr(iptLine.find(':') + 2);
            iptLine = iptLine + ",";
            string temp = "";
            for (char ch : iptLine) {
                if (ch == ' ') {
                    continue;
                }
                else if (ch == ',') {
                    newMonkey.items.push_back(std::stoi(temp));
                    temp = "";
                }
                else {
                    temp = temp + ch;
                }
            }
            // get operation
            std::getline(std::cin, iptLine);
            iptLine = iptLine.substr(iptLine.find('=') + 2);
            long long num;
            if (iptLine[0] >= '0' && iptLine[0] <= '9') {
                num = std::stoi(iptLine.substr(0, iptLine.find(' ')));
            }
            else {
                num = -1;
            }
            newMonkey.oper.num1 = num;
            newMonkey.oper.operatorr = iptLine[iptLine.find(' ') + 1];
            iptLine = iptLine.substr(iptLine.find(newMonkey.oper.operatorr) + 2);
            if (iptLine[0] >= '0' && iptLine[0] <= '9') {
                num = std::stoi(iptLine);
            }
            else {
                num = -1;
            }
            newMonkey.oper.num2 = num;
            // get testNum
            std::getline(std::cin, iptLine);
            iptLine = iptLine.substr(iptLine.find('y') + 2);
            newMonkey.testNum = std::stoi(iptLine);
            // get if true
            std::getline(std::cin, iptLine);
            iptLine = iptLine.substr(iptLine.find('y') + 2);
            newMonkey.trueDest = std::stoi(iptLine);
            // get if false
            std::getline(std::cin, iptLine);
            iptLine = iptLine.substr(iptLine.find('y') + 2);
            newMonkey.falseDest = std::stoi(iptLine);
            std::getline(std::cin, iptLine);
            L->push_back(newMonkey);
        }
        else {
            std::cout << "some thing is wrong" << std::endl;
            break;
        }
    }
}

long long ans(vector<Monkey>* L, long long magicNumber)
{
    long long round = 10000;
    for (long long i = 0; i < round; i++) {
        for (long long monkeyIndex = 0; monkeyIndex < L->size(); monkeyIndex++) {
            while (L->at(monkeyIndex).items.empty() == false) {
                long long item = L->at(monkeyIndex).items.front();
                L->at(monkeyIndex).items.erase(L->at(monkeyIndex).items.begin());
                L->at(monkeyIndex).inspectTimes++;
                long long num1 = L->at(monkeyIndex).oper.num1;
                long long num2 = L->at(monkeyIndex).oper.num2;
                if (num1 == -1) {
                    num1 = item;
                }
                if (num2 == -1) {
                    num2 = item;
                }
                char O = L->at(monkeyIndex).oper.operatorr;
                if (O == '+') {
                    item = num1 + num2;
                }
                else if (O == '*') {
                    item = num1 * num2;
                }
                else {
                    std::cout << "you fucked up" << std::endl;
                }
                item %= magicNumber;
                if (item % L->at(monkeyIndex).testNum == 0) {
                    L->at(L->at(monkeyIndex).trueDest).items.push_back(item);
                }
                else {
                    L->at(L->at(monkeyIndex).falseDest).items.push_back(item);
                }
            }
        }
        // std::cout << "round " << i + 1 << " summery:" << std::endl;
        // for (auto theMonkey : *L) {
        //     std::cout << theMonkey.index << " have: ";
        //     for (auto item : theMonkey.items) {
        //         std::cout << item << ", ";
        //     }
        //     std::cout << std::endl;
        // }
    }
    // compute answer
    long long first = 0;
    long long second = 0;
    for (auto theMonkey : *L) {
        if (theMonkey.inspectTimes > first) {
            second = first;
            first = theMonkey.inspectTimes;
        }
        else if (theMonkey.inspectTimes > second) {
            second = theMonkey.inspectTimes;
        }
    }
    return first * second;
}

long long getMagicNumber(vector<Monkey>* L)
{
    int res = 1;
    for (auto aMonkey : *L) {
        res *= aMonkey.testNum;
    }
    return res;
}
