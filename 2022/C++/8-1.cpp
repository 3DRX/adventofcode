#include <cstdio>
#include <iostream>

#define SIZE 99

int  grid[SIZE][SIZE];
bool scenic_score[SIZE][SIZE];

void input(void);
void north(void);
void south(void);
void west(void);
void east(void);
int  ans(void);

int main(void)
{
    input();
    for (int i = 0; i < SIZE; i++) {
        for (int k = 0; k < SIZE; k++) {
            printf("%d", grid[i][k]);
        }
        printf("\n");
    }
    north();
    south();
    west();
    east();
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

void north(void)
{
    printf("north:\n");
    for (int k = 1; k < SIZE - 1; k++) {
        int largest = grid[0][k];
        printf("k: %d\n", k);
        for (int i = 1; i < SIZE - 1; i++) {
            printf("largest: %d\n", largest);
            if (grid[i][k] <= largest) {
            }
            else {
                scenic_score[i][k] = true;
                largest = grid[i][k];
            }
        }
    }
}

void west(void)
{
    for (int i = 1; i < SIZE - 1; i++) {
        int largest = grid[i][0];
        for (int k = 1; k < SIZE - 1; k++) {
            if (grid[i][k] <= largest) {
            }
            else {
                scenic_score[i][k] = true;
                largest = grid[i][k];
            }
        }
    }
}

void south(void)
{
    for (int k = 1; k < SIZE - 1; k++) {
        int largest = grid[SIZE - 1][k];
        for (int i = SIZE - 2; i > 0; i--) {
            if (grid[i][k] <= largest) {
            }
            else {
                scenic_score[i][k] = true;
                largest = grid[i][k];
            }
        }
    }
}

void east(void)
{
    for (int i = 1; i < SIZE - 1; i++) {
        int largest = grid[i][SIZE - 1];
        for (int k = SIZE - 2; k > 0; k--) {
            if (grid[i][k] <= largest) {
            }
            else {
                scenic_score[i][k] = true;
                largest = grid[i][k];
            }
        }
    }
}

int ans(void)
{
    int res = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int k = 0; k < SIZE; k++) {
            if (scenic_score[i][k] == true) {
                res++;
                printf("1");
            }
            else {
                printf("0");
            }
        }
        printf("\n");
    }
    return res;
}
