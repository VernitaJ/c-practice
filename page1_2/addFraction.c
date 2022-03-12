#include <stdio.h>

int fractions(int, int, int, int);
void printFractions(int, int, int);
int addFraction(int, int, int);
int subFraction(int, int, int);
int mulFraction(int, int, int);

int main(int argc, char const *argv[])
{
    int result = fractions(1, 1, 13, 3);
    //printf("%d", result);
    /* code */
    return 0;
}

int fractions(int a, int b, int c, int d)
{
    if (c == d){
        printFractions(a, b, c);
        return 1;
    } else if (d > c) {
        int multiplier = d/c;
        c *= multiplier;
        a *= multiplier;
        printFractions(a, b, d);
        return 1;
    } else {
        int multiplier = c/d;
        d *= multiplier;
        b *= multiplier;
        printFractions(a, b, c);
        return 1;
    }
    return 0;
}

void printFractions(int a, int b, int denominator)
{
    addFraction(a,b,denominator);
    subFraction(a,b,denominator);
    mulFraction(a,b,denominator);
}

int addFraction(int a, int b, int denominator)
{
 printf("Added: %d/%d ", a+b, denominator);
}

int subFraction(int a, int b, int denominator) 
{
 printf("Subtracted: %d/%d ", a-b, denominator);
}

int mulFraction(int a, int b, int denominator)
{
    printf("Multiplied: %d/%d ", a*b, denominator);
}