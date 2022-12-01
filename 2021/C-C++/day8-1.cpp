#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

int len(char* str)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++) {
    }
    return i;
}

int main(void)
{
    int  count_word = -1;
    int  ans = 0;
    char iptbuf[8];
    for (int i = 0; i < 8; i++) {
        iptbuf[i] = '\0';
    }
    while (1) {
        scanf("%s", iptbuf);
        if (iptbuf[0] == '#') {
            break;
        }
        if (count_word == -1) {
            if (iptbuf[0] == '|') {
                count_word = 0;
            }
        }
        else {
            if (len(iptbuf) == 2 || len(iptbuf) == 4 || len(iptbuf) == 3 || len(iptbuf) == 7) {
                ans++;
                // printf("ans=%d\n", ans);
            }
            count_word++;
            if (count_word == 4) {
                count_word = -1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
