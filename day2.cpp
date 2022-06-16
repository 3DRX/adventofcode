#include <cstdio>
#include <cstring>

int main(void)
{
    long long depth = 0;
    long long hp = 0;
    long long X = 0;
    char inputBuf[10];

    for (int i = 0; i < 1000; i++) {
        X = 0;
        scanf("%s",inputBuf);
        if (strcmp(inputBuf, "forward") == 0) {
            scanf("%lld",&X);
            hp += X;
            X = 0;
        }
        else if (strcmp(inputBuf, "up") == 0) {
            scanf("%lld",&X);
            if (depth - X >= 0) {
                depth -= X;
            }
            X = 0;
        }
        else if (strcmp(inputBuf, "down") == 0) {
            scanf("%lld",&X);
            depth += X;
            X = 0;
        }
        else {
            printf("you fucked up\n");
        }
    }

    printf("%lld", depth * hp);
    return 0;
}
