#include <cstdio>
#include <vector>

int main(void)
{
    long fisheeeeeeeeees[9] = { 0 };
    int              ipt[] = { 1, 3, 1, 5, 5, 1, 1, 1, 5, 1, 1, 1, 3, 1, 1, 4, 3, 1, 1, 2, 2, 4, 2, 1, 3, 3, 2, 4, 4, 4, 1, 3, 1, 1, 4, 3, 1, 5, 5, 1, 1, 3, 4, 2, 1, 5, 3, 4, 5, 5, 2, 5, 5, 1, 5, 5, 2, 1, 5, 1, 1, 2, 1, 1, 1, 4, 4, 1, 3, 3, 1, 5, 4, 4, 3, 4, 3, 3, 1, 1, 3, 4, 1, 5, 5, 2, 5, 2, 2, 4, 1, 2, 5, 2, 1, 2, 5, 4, 1, 1, 1, 1, 1, 4, 1, 1, 3, 1, 5, 2, 5, 1, 3, 1, 5, 3, 3, 2, 2, 1, 5, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 5, 3, 5, 2, 5, 2, 2, 2, 1, 1, 1, 5, 5, 2, 2, 1, 1, 3, 4, 1, 1, 3, 1, 3, 5, 1, 4, 1, 4, 1, 3, 1, 4, 1, 1, 1, 1, 2, 1, 4, 5, 4, 5, 5, 2, 1, 3, 1, 4, 2, 5, 1, 1, 3, 5, 2, 1, 2, 2, 5, 1, 2, 2, 4, 5, 2, 1, 1, 1, 1, 2, 2, 3, 1, 5, 5, 5, 3, 2, 4, 2, 4, 1, 5, 3, 1, 4, 4, 2, 4, 2, 2, 4, 4, 4, 4, 1, 3, 4, 3, 2, 1, 3, 5, 3, 1, 5, 5, 4, 1, 5, 1, 2, 4, 2, 5, 4, 1, 3, 3, 1, 4, 1, 3, 3, 3, 1, 3, 1, 1, 1, 1, 4, 1, 2, 3, 1, 3, 3, 5, 2, 3, 1, 1, 1, 5, 5, 4, 1, 2, 3, 1, 3, 1, 1, 4, 1, 3, 2, 2, 1, 1, 1, 3, 4, 3, 1, 3 };
    //int ipt[] = { 3, 4, 3, 1, 2 };
    int dayCount = 0;
    for (auto i : ipt) {
        fisheeeeeeeeees[i]++;
    }
    while (dayCount < 256) {
        long tempZero = fisheeeeeeeeees[0];
        for (int i = 0; i < 8; i++) {
            fisheeeeeeeeees[i] = fisheeeeeeeeees[i + 1];
        }
        fisheeeeeeeeees[8] = tempZero;
        fisheeeeeeeeees[6] += tempZero;
        dayCount++;
    }
    long ans = 0;
    for (auto i : fisheeeeeeeeees) {
        ans += i;
    }
    printf("%ld\n", ans);
    return 0;
}
