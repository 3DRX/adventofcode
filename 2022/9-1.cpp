#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;

typedef struct _node {
    char direction;
    int  num;
    _node(char direction, int num)
    {
        this->direction = direction;
        this->num = num;
    }
} node;

struct coordinate {
    int x;
    int y;
    coordinate(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    bool operator==(const coordinate& t) const
    {
        return x == t.x && y == t.y;
    }
};

struct coordinateHash {
    size_t operator()(const coordinate& t) const
    {
        return t.x * 100 + t.y;
    }
};

void input(std::vector<node>* L);
int  answer(std::vector<node>* L);

int main(void)
{
    std::vector<node> L;
    input(&L);
    // std::cout << "helloworld" << std::endl;
    std::cout << answer(&L) << std::endl;
    return 0;
}

void input(std::vector<node>* L)
{
    while (1) {
        string iptLine;
        std::getline(std::cin, iptLine);
        if (iptLine == "") {
            break;
        }
        else {
            L->push_back(_node(iptLine[0], std::stoi(iptLine.substr(2))));
        }
    }
}

void updateTailPosition(coordinate* tailPosition, coordinate* headPosition)
{
    if (abs(tailPosition->x - headPosition->x) <= 1 && abs(tailPosition->y - headPosition->y) <= 1) {
        // If H and T adjacent or overlap, do nothing
        return;
    }
    // H and T are on same lone or same row
    if (tailPosition->x == headPosition->x) {
        if (headPosition->y > tailPosition->y) {
            tailPosition->y++;
        }
        else {
            tailPosition->y--;
        }
    }
    else if (tailPosition->y == headPosition->y) {
        if (headPosition->x > tailPosition->x) {
            tailPosition->x++;
        }
        else {
            tailPosition->x--;
        }
    }
    else { // H and T are NOT on same line or same row
        int Tx = tailPosition->x;
        int Ty = tailPosition->y;
        int Hx = headPosition->x;
        int Hy = headPosition->y;
        if (Hx - Tx == 1) {
            tailPosition->x++;
            updateTailPosition(tailPosition, headPosition);
        }
        else if (Hx - Tx == -1) {
            tailPosition->x--;
            updateTailPosition(tailPosition, headPosition);
        }
        else if (Hy - Ty == 1) {
            tailPosition->y++;
            updateTailPosition(tailPosition, headPosition);
        }
        else if (Hy - Ty == -1) {
            tailPosition->y--;
            updateTailPosition(tailPosition, headPosition);
        }
    }
}

int answer(std::vector<node>* L)
{
    std::unordered_set<coordinate, coordinateHash> SET;
    // coordinate of Tail
    coordinate tailPosition = coordinate(0, 0);
    coordinate headPosition = coordinate(0, 0);
    SET.insert(tailPosition);
    for (auto instruction : *L) {
        // for each line of the input
        for (int i = 0; i < instruction.num; i++) {
            // for each step the Head moves
            if (instruction.direction == 'R') {
                headPosition.x++;
            }
            else if (instruction.direction == 'L') {
                headPosition.x--;
            }
            else if (instruction.direction == 'U') {
                headPosition.y++;
            }
            else { // 'D'
                headPosition.y--;
            }
            // find out the coordinate of Tail after the movement and put it into SET
            updateTailPosition(&tailPosition, &headPosition);
            if (SET.count(tailPosition) == 0) {
                SET.insert(tailPosition);
            }
        }
    }
    return SET.size();
}
