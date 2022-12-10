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

int ans(vector<line>* L)
{
    int signalStrength = 0;
    int X = 1;
    int cycle = 1;
    for (auto line : *L) {
        if (line.command == "noop") {
            updateSignalStrength(&signalStrength, &X, &cycle);
        }
        else {
            updateSignalStrength(&signalStrength, &X, &cycle);
            X += line.value;
            updateSignalStrength(&signalStrength, &X, &cycle);
        }
        std::cout << "==================" << std::endl;
        if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220) {
            std::cout << "cycle: " << cycle << std::endl;
            std::cout << "X*cycle: " << X * cycle << std::endl;
        }
        std::cout << "X: " << X << std::endl;
        std::cout << "==================" << std::endl;
    }
    return signalStrength;
}
