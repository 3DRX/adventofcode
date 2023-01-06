#include <cstdio>
#include <iostream>
#include <vector>

using std::vector;

typedef struct _S {
    int A_low;
    int A_high;
    int B_low;
    int B_high;
} S;

void input(vector<S>* LI);
int  ans(vector<S>* LI);

int main(void)
{
    vector<S>* LI = new vector<S>;
    input(LI);
    std::cout << ans(LI) << std::endl;
    return 0;
}

void input(vector<S>* LI)
{
    while (1) {
        S newNode;
        scanf("%d", &newNode.A_low);
        if (newNode.A_low == -1) {
            return;
        }
        getchar();
        scanf("%d", &newNode.A_high);
        getchar();
        scanf("%d", &newNode.B_low);
        getchar();
        scanf("%d", &newNode.B_high);
        getchar();
        LI->push_back(newNode);
    }
}

int ans(vector<S>* LI)
{
    int ans = 0;
    for (auto i : *LI) {
        if (i.A_high < i.B_low || i.B_high < i.A_low) {
        }
        else {
            ans++;
        }
    }
    return ans;
}
