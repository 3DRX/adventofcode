#include <cstdio>
#include <iostream>

#define SIZE 99

int grid[SIZE][SIZE];
int scenic_score[SIZE][SIZE];

void input(void);
int  ans(void);
int  getScore(int i, int k);

int main(void)
{
    input();
    for (int i = 0; i < SIZE; i++) {
        for (int k = 0; k < SIZE; k++) {
            printf("%d", grid[i][k]);
        }
        printf("\n");
    }
    printf("%d\n", ans());
    return 0;
}

void input(void)
{
    for (int i = 0; i < SIZE; i++) {
        for (int k = 0; k < SIZE; k++) {
            grid[i][k] = getchar() - '0';
            if (i == 0 || i == SIZE - 1 || k == 0 || k == SIZE - 1) {
                scenic_score[i][k] = true;
            }
            else {
                scenic_score[i][k] = false;
            }
        }
        getchar();
    }
}

int ans(void)
{
    int res = 0;
    for (int i = 1; i < SIZE - 1; i++) {
        for (int k = 1; k < SIZE - 1; k++) {
            int score = getScore(i, k);
            if (score > res) {
                res = score;
            }
        }
    }
    return res;
}

int getScore(int i, int k)
{
    // printf("i: %d k: %d\n", i, k);
    int left = 0;
    int right = 0;
    int top = 0;
    int down = 0;
    int ownHeight = grid[i][k];
    int index;
    // printf("start left\n");
    index = k;
    while (1) {
        // printf("index: %d\n", index);
        index--;
        left++;
        if ((index != k && grid[i][index] >= ownHeight) || index == 0 || index == SIZE - 1) {
            break;
        }
    }
    // printf("start right\n");
    index = k;
    while (1) {
        right++;
        index++;
        if ((index != k && grid[i][index] >= ownHeight) || index == 0 || index == SIZE - 1) {
            break;
        }
    }
    // printf("start top\n");
    index = i;
    while (1) {
        top++;
        index--;
        if ((index != i && grid[index][k] >= ownHeight) || index == 0 || index == SIZE - 1) {
            break;
        }
    }
    // printf("start down\n");
    index = i;
    while (1) {
        down++;
        index++;
        if ((index != i && grid[index][k] >= ownHeight) || index == 0 || index == SIZE - 1) {
            break;
        }
    }
    // printf("left: %d\n", left);
    // printf("right: %d\n", right);
    // printf("top: %d\n", top);
    // printf("down: %d\n", down);
    return left * right * top * down;
}
