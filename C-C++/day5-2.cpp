#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <vector>

#define INPUTLENGTH 500

typedef struct {
    int x1;
    int x2;
    int y1;
    int y2;
} line;
std::vector<line> lines;
int               maxX = 0;
int               maxY = 0;

void input(void)
{
    int   iptx1 = 0;
    int   iptx2 = 0;
    int   ipty1 = 0;
    int   ipty2 = 0;
    char* a = (char*)malloc(sizeof(char) * 3);
    for (int i = 0; i < INPUTLENGTH; i++) {
        scanf("%d", &iptx1);
        getchar();
        scanf("%d", &ipty1);
        scanf("%s", a);
        scanf("%d", &iptx2);
        getchar();
        scanf("%d", &ipty2);
        if (iptx1 > maxX) {
            maxX = iptx1;
        }
        if (iptx2 > maxX) {
            maxX = iptx2;
        }
        if (ipty1 > maxY) {
            maxY = ipty1;
        }
        if (ipty2 > maxY) {
            maxY = ipty2;
        }
        line newLine;
        newLine.x1 = iptx1;
        newLine.x2 = iptx2;
        newLine.y1 = ipty1;
        newLine.y2 = ipty2;
        lines.push_back(newLine);
    }
}

void filter(void)
{
    for (auto iter = lines.begin(); iter < lines.end();) {
        if (
            (*iter).x1 == (*iter).x2 || (*iter).y1 == (*iter).y2 || (((*iter).y2 - (*iter).y1) / ((*iter).x2 - (*iter).x1)) == 1 || (((*iter).y2 - (*iter).y1) / ((*iter).x2 - (*iter).x1)) == -1) {
            // vertical, horizontal, or diagonal
            iter++;
        }
        else {
            printf("deleted: ");
            printf("x1:%d y1:%d x2:%d y2:%d\n", (*iter).x1, (*iter).y1, (*iter).x2, (*iter).y2);
            iter = lines.erase(iter);
        }
    }
}

int main(void)
{
    int count = 0;
    lines.clear();
    lines.shrink_to_fit();
    input();
    printf("start===============================\n");
    for (auto i : lines) {
        printf("x1:%d y1:%d x2:%d y2:%d\n", i.x1, i.y1, i.x2, i.y2);
    }
    printf("end===============================\n");
    filter();
    printf("start===============================\n");
    for (auto i : lines) {
        printf("x1:%d y1:%d x2:%d y2:%d\n", i.x1, i.y1, i.x2, i.y2);
    }
    printf("end===============================\n");
    char grid[maxX + 1][maxY + 1];
    for (int x = 0; x <= maxX; x++) {
        for (int y = 0; y <= maxY; y++) {
            grid[x][y] = '.';
        }
    }
    for (auto i : lines) {
        if (i.x1 == i.x2) {
            for (int k = std::min(i.y1, i.y2); k <= std::max(i.y1, i.y2); k++) {
                if (grid[i.x1][k] == '.') {
                    grid[i.x1][k] = '1';
                }
                else if (grid[i.x1][k] == '1') {
                    grid[i.x1][k]++;
                    count++;
                }
                else {
                    grid[i.x1][k]++;
                }
            }
        }
        else if (i.y1 == i.y2) {
            for (int k = std::min(i.x1, i.x2); k <= std::max(i.x1, i.x2); k++) {
                if (grid[k][i.y1] == '.') {
                    grid[k][i.y1] = '1';
                }
                else if (grid[k][i.y1] == '1') {
                    grid[k][i.y1]++;
                    count++;
                }
                else {
                    grid[k][i.y1]++;
                }
            }
        }
        else if (((i.y2 - i.y1) / (i.x2 - i.x1)) == 1) {
            int temp = std::min(i.y1, i.y2);
            for (int k = std::min(i.x1, i.x2); k <= std::max(i.x1, i.x2); k++) {
                if (grid[k][temp] == '.') {
                    grid[k][temp] = '1';
                }
                else if (grid[k][temp] == '1') {
                    grid[k][temp]++;
                    count++;
                }
                else {
                    grid[k][temp]++;
                }
                temp++;
            }
        }
        else if (((i.y2 - i.y1) / (i.x2 - i.x1)) == -1) {
            int temp = std::max(i.y1, i.y2);
            for (int k = std::min(i.x1, i.x2); k <= std::max(i.x1, i.x2); k++) {
                if (grid[k][temp] == '.') {
                    grid[k][temp] = '1';
                }
                else if (grid[k][temp] == '1') {
                    grid[k][temp]++;
                    count++;
                }
                else {
                    grid[k][temp]++;
                }
                temp--;
            }
        }
    }
    for (int i = 0; i <= maxY; i++) {
        for (int k = 0; k <= maxX; k++) {
            printf("%c", grid[k][i]);
        }
        printf("\n");
    }
    printf("%d", count);
    return 0;
}
