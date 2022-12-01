#include <iostream>
#include <cstdio>

int main(void)
{
    int ipt = 0;
    int prev = -1;
    int ans = 0;
    while (1) {
        scanf("%d",&ipt);
        if (ipt == -1) {
            break;
        }
        else {
            if (prev == -1) {
            }
            else if (prev < ipt) {
                ans++;
            }
            prev = ipt;
        }
    }
    printf("%d\n",ans);
    return 0;
}
