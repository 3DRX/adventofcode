#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define LINE 1000
#define LENGTH 12

int convertBinaryToDecimal(long n);

int main(void)
{
    char data[LINE][LENGTH+1];
    int co2[LINE];
    int oxygen[LINE];
    char co2res[LENGTH+1] = {'\0'};
    char oxygenres[LENGTH+1] = {'\0'};
    for (int i = 0; i < LINE; i++) {
        co2[i] = 1;
        oxygen[i] = 1;
        scanf("%s", data[i]);
    }
    // {{{find oxygen
    int count1 = 0;
    int count0 = 0;
    for (int j = 0; j < LENGTH; j++) {
        count0 = 0;
        count1 = 0;
        for (int i = 0; i < LINE; i++) {
            if (oxygen[i] == -1) {
                continue;
            }
            if (data[i][j] == '1') {
                count1++;
            }
            else if (data[i][j] == '0'){
                count0++;
            }
        }
        if (count1 + count0 == 2) { // only 2 bit strings left
            for (int k = 0; k < LINE; k++) {
                if (oxygen[k] == 1 && data[k][j] == '1') {
                    strcpy(oxygenres, data[k]);
                    break;
                }
            }
            break;
        }
        else if (count1 >= count0) { // more 1 or a tie
            for (int i = 0; i < LINE; i++) {
                if (oxygen[i] == -1) {
                    continue;
                }
                if (data[i][j] != '1') {
                    oxygen[i] = -1;
                    // remove the ones with 0 out of
                    // oxygen list
                }
            }
        }
        else{ // more 0
            for (int i = 0; i < LINE; i++) {
                if (oxygen[i] == -1) {
                    continue;
                }
                if (data[i][j] != '0') {
                    oxygen[i] = -1;
                    // remove the ones with 1 out of
                    // oxygen list
                }
            }
        }
    }
    // }}}
    // {{{find co2
    for (int j = 0; j < LENGTH; j++) {
        // ------------
        printf("j:%d\n",j);
        for (int i = 0; i < LINE; i++) {
            if (co2[i] == 1) {
                printf("%s\n",data[i]);
            }
        }
        // ------------
        count0 = 0;
        count1 = 0;
        for (int i = 0; i < LINE; i++) {
            if (co2[i] == -1) {
                continue;
            }
            if (data[i][j] == '1') {
                count1++;
            }
            else if (data[i][j] == '0'){
                count0++;
            }
        }
        printf("count1:%d\ncount0:%d\n",count1,count0);
        printf("-------------\n");
        if (count1 + count0 == 2) { // only 2 bit strings left
            for (int k = 0; k < LINE; k++) {
                if (co2[k] == 1 && data[k][j] == '0') {
                    printf("hello\n");
                    strcpy(co2res, data[k]);
                    break;
                }
            }
            break;
        }
        else if (count1 + count0 == 1) {
            for (int k = 0; k < LINE; k++) {
                if (co2[k] == 1 ) {
                    printf("hello\n");
                    strcpy(co2res, data[k]);
                    break;
                }
            }
        }
        else if (count1 < count0) { // less 1
            for (int i = 0; i < LINE; i++) {
                if (co2[i] == -1) {
                    continue;
                }
                if (data[i][j] != '1') {
                    co2[i] = -1;
                    // remove the ones with 0 out of
                    // co2 list
                }
            }
        }
        else{ // less 0 or a tie
            for (int i = 0; i < LINE; i++) {
                if (co2[i] == -1) {
                    continue;
                }
                if (data[i][j] != '0') {
                    co2[i] = -1;
                    // remove the ones with 1 out of
                    // co2 list
                }
            }
        }
    }
    // }}}
    long decCo2, decOxygen;
    decCo2 = atol(co2res);
    decOxygen = atol(oxygenres);
    printf("%s\n%s\n",co2res,oxygenres);
    printf("\n===========ANSWER===========\n%d\n",
            convertBinaryToDecimal(decCo2) * convertBinaryToDecimal(decOxygen));
}

int convertBinaryToDecimal(long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}
