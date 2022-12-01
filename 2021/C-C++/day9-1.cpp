#include <cstdio>

#define GRID_SIZE 102

int grid[GRID_SIZE][GRID_SIZE];

void ipt(void)
{
    std::FILE* fPtr = fopen("../input.io", "r");
    char       iptbuf;
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[0][i] = 10;
        grid[i][0] = 10;
        grid[GRID_SIZE - 1][i] = 10;
        grid[i][GRID_SIZE - 1] = 10;
    }
    for (int first_index = 1, second_index = 1; fscanf(fPtr, "%c", &iptbuf) != EOF;) {
        if (iptbuf == '\n') {
            first_index++;
            second_index = 1;
        }
        else {
            grid[first_index][second_index] = iptbuf - '0';
            second_index++;
        }
    }
    // for (int i = 0; i < GRID_SIZE; i++) {
    //     for (int k = 0; k < GRID_SIZE; k++) {
    //         printf("%d", grid[i][k]);
    //     }
    //     printf("\n");
    // }
    fclose(fPtr);
}

int main(void)
{
    ipt();
    int sum = 0;
    for (int i = 1; i <= GRID_SIZE - 2; i++) {
        for (int k = 1; k <= GRID_SIZE - 2; k++) {
            int temp = grid[i][k];
            if (temp < grid[i - 1][k] && temp < grid[i + 1][k] && temp < grid[i][k - 1] && temp < grid[i][k + 1]) {
                sum += temp + 1;
            }
        }
    }
    printf("the ans is: %d\n", sum);
    return 0;
}
