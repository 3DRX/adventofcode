#include <cstdio>

int command[] = {79,9,13,43,53,51,40,47,56,27,0,14,33,60,61,36,72,48,83,42,10,86,41,75,16,80,15,93,95,45,68,96,84,11,85,63,18,31,35,74,71,91,39,88,55,6,21,12,58,29,69,37,44,98,89,78,17,64,59,76,54,30,65,82,28,50,32,77,66,24,1,70,92,23,8,49,38,73,94,26,22,34,97,25,87,19,57,7,2,3,46,67,90,62,20,5,52,99,81,4,-1};
int grids[100][5][5];
bool lit[100][5][5];

void input(void)
{
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                scanf("%d",grids[i][j]+k);
                lit[i][k][k] = false;
            }
        }
    }
    //for (int i = 0; i < 100; i++) {
        //for (int j = 0; j < 5; j++) {
            //for (int k = 0; k < 5; k++) {
                //printf("%d",*(grid[i][j]+k));
            //}
            //printf("\n");
        //}
        //printf("\n");
    //}
}

/**if game end, return the index of grid
 * else, return -1
 */
int gameEnd(void)
{
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 5; j++) {
            if (lit[i][j][0] && lit[i][j][1] && lit[i][j][2] && lit[i][j][3] && lit[i][j][4]) {
                return i;
            }
        }
        for (int j = 0; j < 5; j++) {
            if (lit[i][0][j] && lit[i][1][j] && lit[i][2][j] && lit[i][3][j] && lit[i][4][j]) {
                return i;
            }
        }
    }
    return -1;
}

/**calculate the sum of the numbers that are not lit in a grid
 */
int calSum(int winGrid)
{
    int sum = 0;
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
            if (lit[winGrid][j][k] == false) {
                sum += grids[winGrid][j][k];
            }
        }
    }
    return sum;
}

int main(void)
{
    input();
    int ipt = 0;
    int winGrid = -1;
    while (true) {
        if (command[ipt] == -1) {
            break;
        }
        for (int i = 0; i < 100; i++) { // lit the number called
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (grids[i][j][k] == command[ipt]) {
                        lit[i][j][k] = true;
                    }
                }
            }
        }
        winGrid = gameEnd();
        if (winGrid != -1) {
            break;
        }
        ipt++;
    }
    int sum = calSum(winGrid);
    printf("%d\n", command[ipt] * sum);
    return 0;
}

