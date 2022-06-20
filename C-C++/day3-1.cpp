#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <pthread.h>

#define LINE 1000
#define LENGTH 12

int convertBinaryToDecimal(long n);

int main(void)
{
    char data[LINE][LENGTH+1];
    char gamma[LENGTH+1];
    char epsilon[LENGTH+1];
    int zero = 0;
    int one = 0;
    int index = 0;
    for (int i = 0; i < LINE; i++) {
        scanf("%s", data[i]);
    }
    for (index = 0; index < LENGTH; index++) {
        zero = 0;
        one = 0;
        for (int i = 0; i < LINE; i++) {
            if (data[i][index] == '0') {
                zero++;
            }
            else if (data[i][index] == '1') {
                one++;
            }
            else {
                fprintf(stderr, "char other than 0 or 1: %d\n",
                        data[i][index]);
                exit(EXIT_FAILURE);
            }
        }
        if (zero > one) {
            gamma[index] = '0';
            epsilon[index] = '1';
        }
        else if (zero < one) {
            gamma[index] = '1';
            epsilon[index] = '0';
        }
        else {
            fprintf(stderr, "same amount of 1 and 0\n");
        }
    }
    // convert binary into decimal
    long decGamma, decEpsilon;
    decGamma = atol(gamma);
    decEpsilon = atol(epsilon);
    printf("%d\n",
            convertBinaryToDecimal(decGamma) * convertBinaryToDecimal(decEpsilon));
    return 0;
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
