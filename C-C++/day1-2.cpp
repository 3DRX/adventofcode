#include <cstdio>

int main(void)
{
    int previous = -1;
    int ans = 0;
    int data[2000];
    for (int i = 0; i < 2000; i++) {
        scanf("%d", data + i);
    }
    for (int i = 0; i < 1998; i++) {
        int newSum = data[i] + data[i+1] + data[i+2];
        if (previous == -1) {
        }
        else if (newSum > previous) {
            ans++;
        }
        previous = newSum;
    }
    printf("%d\n", ans);
    return 0;
}

