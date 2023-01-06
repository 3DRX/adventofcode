#include <cstdio>
#include <limits>
#include <queue>
#include <stack>
#include <vector>

using std::queue;
using std::stack;
using std::vector;

typedef struct {
    int num;
    int from;
    int to;
} S;

void inputStack(stack<char>* ST);
void input(vector<S>* LI);

int main(void)
{
    vector<S>*  LI = new vector<S>;
    stack<char> Stacks[9];
    inputStack(Stacks);
    input(LI);
    stack<char> temp;
    for (auto L : *LI) {
        for (int i = 0; i < L.num; i++) {
            char item = Stacks[L.from - 1].top();
            temp.push(item);
            Stacks[L.from - 1].pop();
        }
        while (temp.empty() == false) {
            Stacks[L.to - 1].push(temp.top());
            temp.pop();
        }
    }
    for (auto Stack : Stacks) {
        printf("%c", Stack.top());
    }
    return 0;
}

void inputStack(stack<char>* ST)
{
    ST[0].push('P');
    ST[0].push('F');
    ST[0].push('M');
    ST[0].push('Q');
    ST[0].push('W');
    ST[0].push('G');
    ST[0].push('R');
    ST[0].push('T');

    ST[1].push('H');
    ST[1].push('F');
    ST[1].push('R');

    ST[2].push('P');
    ST[2].push('Z');
    ST[2].push('R');
    ST[2].push('V');
    ST[2].push('G');
    ST[2].push('H');
    ST[2].push('S');
    ST[2].push('D');

    ST[3].push('Q');
    ST[3].push('H');
    ST[3].push('P');
    ST[3].push('B');
    ST[3].push('F');
    ST[3].push('W');
    ST[3].push('G');

    ST[4].push('P');
    ST[4].push('S');
    ST[4].push('M');
    ST[4].push('J');
    ST[4].push('H');

    ST[5].push('M');
    ST[5].push('Z');
    ST[5].push('T');
    ST[5].push('H');
    ST[5].push('S');
    ST[5].push('R');
    ST[5].push('P');
    ST[5].push('L');

    ST[6].push('P');
    ST[6].push('T');
    ST[6].push('H');
    ST[6].push('N');
    ST[6].push('M');
    ST[6].push('L');

    ST[7].push('F');
    ST[7].push('D');
    ST[7].push('Q');
    ST[7].push('R');

    ST[8].push('D');
    ST[8].push('S');
    ST[8].push('C');
    ST[8].push('N');
    ST[8].push('L');
    ST[8].push('P');
    ST[8].push('H');
}

void input(vector<S>* LI)
{
    char buf[10];
    S    newNode;
    while (1) {
        scanf("%s", buf);
        scanf("%d", &newNode.num);
        scanf("%s", buf);
        scanf("%d", &newNode.from);
        scanf("%s", buf);
        scanf("%d", &newNode.to);
        getchar();
        if (newNode.num == -1) {
            break;
        }
        else {
            LI->push_back(newNode);
        }
    }
}
