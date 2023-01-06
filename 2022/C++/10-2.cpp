#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct line {
    string command;
    int    value;
    line(string command, int value)
    {
        this->command = command;
        this->value = value;
    }
};

void input(vector<line>* L);
int  ans(vector<line>* L);

int main(void)
{
    vector<line> L;
    input(&L);
    std::cout << ans(&L) << std::endl;
    return 0;
}

void input(vector<line>* L)
{
    string iptLine;
    while (1) {
        std::getline(std::cin, iptLine);
        if (iptLine == "") {
            break;
        }
        else {
            string command = iptLine.substr(0, 4);
            if (command == "addx") {
                L->push_back(line(command, std::stoi(iptLine.substr(5))));
            }
            else {
                L->push_back(line(command, 0));
            }
        }
    }
}

void updateSignalStrength(int* signalStrength, int* X, int* cycle)
{
    (*cycle)++;
    if (*cycle == 20 || *cycle == 60 || *cycle == 100 || *cycle == 140 || *cycle == 180 || *cycle == 220) {
        *signalStrength += *X * *cycle;
    }
}

void display(int* X, int* cycle)
{
    int C = *cycle % 40;
    if (C == 0) {
        C = 40;
    }
    if (C == *X || C == *X + 1 || C == *X + 2) {
        std::cout << '#';
    }
    else {
        std::cout << ' ';
    }
    if (C == 40) {
        std::cout << std::endl;
    }
}

int ans(vector<line>* L)
{
    int signalStrength = 0;
    int X = 1;
    int cycle = 1;
    for (auto line : *L) {
        if (line.command == "noop") {
            display(&X, &cycle);
            updateSignalStrength(&signalStrength, &X, &cycle);
        }
        else {
            display(&X, &cycle);
            updateSignalStrength(&signalStrength, &X, &cycle);
            display(&X, &cycle);
            X += line.value;
            updateSignalStrength(&signalStrength, &X, &cycle);
        }
    }
    return signalStrength;
}
