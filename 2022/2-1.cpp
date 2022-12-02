#include <cstdio>

int matchRes(char first, char second);

int main(void)
{
    int score = 0;
    while (1) {
        char first, second;
        scanf("%c", &first);
        getchar();
        scanf("%c", &second);
        getchar();
        if (first == 'E' && second == 'E') {
            printf("the score is: %d\n", score);
            break;
        }
        score += matchRes(first, second) * 3 + (second - 'X' + 1);
    }
    return 0;
}

int matchRes(char first, char second)
{
    if (first == 'A') {
        if (second == 'X') {
            return 1;
        }
        else if (second == 'Y') {
            return 2;
        }
        else {
            return 0;
        }
    }
    else if (first == 'B') {
        if (second == 'X') {
            return 0;
        }
        else if (second == 'Y') {
            return 1;
        }
        else {
            return 2;
        }
    }
    else {
        if (second == 'X') {
            return 2;
        }
        else if (second == 'Y') {
            return 0;
        }
        else {
            return 1;
        }
    }
}
