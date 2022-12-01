#include <cstdio>
#include <cstring>

int main(void)
{
    int aim = 0;
    int horiPos = 0;
    int depth = 0;
    int X = 0;
    char inputBuf[20];
    for (int i = 0; i < 1000; i++) {
        scanf("%s",inputBuf);
        scanf("%d",&X);
        if (strcmp("forward", inputBuf) == 0) {
            horiPos += X;
            depth += (aim * X);
        }
        else if (strcmp("down", inputBuf) == 0) {
            aim += X;
        }
        else if (strcmp("up", inputBuf) == 0) {
            aim -= X;
        }
    }
    printf("%d", horiPos * depth);
    return 0;
}
