#include <stdio.h>

void toggle(int, int);
void toDecimal(int[]);

int main(int argc, char const *argv[])
{
    int num, shift;
    printf("Input number");
    scanf("%d", &num);
    printf("nth bit to toggle");
    scanf("%d", &shift);

    toggle(num, shift);
    // next line
    return 0;
}

void toggle(int num, int shift)
{
    int binary[8];
    for (int i = 0; i < 8; i++)
    {
        binary[i] = (char)(num >> i) & 1;
    }
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    printf("\n");
    binary[shift - 1] = !binary[shift - 1];
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    toDecimal(binary);
}

void toDecimal(int binary[])
{
    // num |=
    // int n = 0;
    // int multiplier = 1;
    // for (int i = 0; i < 8; i++)
    // {
    //     if (binary[i] == 1){
    //         n+= multiplier;
    //     }
    //     multiplier*=2;
    // }
    // int n = 0;
    // int i;
    // for (i = 7; i >= 0; i--)
    // {
    //     n <<= 1;
    //     printf("n during = %d ", n);
    //     n += binary[i];
    //     printf("n after = %d\n ", n);
    // }
    int sum = 0;
    for (int i = 0, j = 0; i < 8; i++, j++)
    {
        sum += binary[j] * (1 << i);
    }
    printf("number: %d", sum);
}