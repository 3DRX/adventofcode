#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ostream>
#include <vector>
#include <iostream>

typedef struct{
    int x1;
    int x2;
    int y1;
    int y2;
} line;
std::vector<line> lines;
int maxX = 0;
int maxY = 0;

void input(void)
{
    int iptx1 = 0;
    int iptx2 = 0;
    int ipty1 = 0;
    int ipty2 = 0;
    char * a = (char *)malloc(sizeof(char) * 3);
    for (int i = 0; i < 500; i++) {
        scanf("%d",&iptx1);
        getchar();
        scanf("%d",&ipty1);
        scanf("%s",a);
        scanf("%d",&iptx2);
        getchar();
        scanf("%d",&ipty2);
        if (iptx1 > maxX) {maxX = iptx1;}
        if (iptx2 > maxX) {maxX = iptx2;}
        if (ipty1 > maxY) {maxY = ipty1;}
        if (ipty2 > maxY) {maxY = ipty2;}
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
    for (auto iter = lines.begin(); iter < lines.end(); iter++) {
        if ((*iter).x1 == (*iter).x2 || (*iter).y1 == (*iter).y2) {
        }
        else {
            lines.erase(iter);
        }
    }
}

void editGrid(char **x)
{
}

int main(void)
{
    lines.clear();
    lines.shrink_to_fit();
    input();
    filter();
    char grid[maxX][maxY];
    for (int x = 0; x < maxX; x++) {
        for (int y = 0; y < maxY; y++) {
            grid[x][y] = '.';
        }
    }
    editGrid(&(&grid[0]));
    return 0;
}
