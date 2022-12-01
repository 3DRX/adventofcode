#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

typedef struct {
    char tenWds[10][8];
    char fourWds[4][8];
} wds;

string digits_key[] = {
    "abcefg",
    "cf",
    "acdeg",
    "acdfg",
    "bcdf",
    "abdfg",
    "abdefg",
    "acf",
    "abcdefg",
    "abcdfg"
};

vector<wds> data;

void ipt(void)
{
    // load input data to vector<wds> data
    int count_word = 0;
    while (1) {
        char iptbuf[8];
        wds  temp;
        scanf("%s", iptbuf);
        count_word++;
        if (iptbuf[0] == '#') {
            break;
        }
        if (count_word <= 11) {
            if (iptbuf[0] == '|') {
                count_word = 11;
                continue;
            }
            std::strcpy(temp.tenWds[count_word - 1], iptbuf);
        }
        else {
            std::strcpy(temp.fourWds[count_word - 12], iptbuf);
            if (count_word == 15) {
                count_word = 0;
                data.push_back(temp);
            }
        }
    }
}

int getNum(int index)
{
    // return the result of the indexth element in data
    int  res = 0;
    char sigma[] = "abcdefg";
    char key[7] = { '\0' };
    do {
        for (int i = 0; i < 7; i++) {
            key[i] = sigma[i];
        }
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 8; k++) {
                printf("%c", data[index].tenWds[i][k]);
            }
        }
    } while (std::next_permutation(sigma, sigma + 7));
    return res;
}

int main(void)
{
    ipt();
    int ans = 0;
    // loop through data and add each result to int ans
    // for (auto i = 0; i < data.size(); i++) {
    for (auto i = 0; i < 2; i++) {
        ans += getNum(i);
    }
    printf("The ans is: %d\n", ans);
    return 0;
}
