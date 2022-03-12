#include <stdio.h>

void trailing(int);

int main(int argc, char const *argv[])
{
    int input;
    printf("Input any number: ");
    scanf("%d", &input);
    getchar();
    trailing(input);
    return 0;
}

void trailing(int input)
{
    int binary[8];
    for (int i = 0; i < 8; i++)
    {
        binary[i] = (char)(input >> i) & 1;
    }
    int num = 0;
    int j = 0;
    while(binary[j] == 0)
    {
        num += (binary[j] * (1 << j)) == 0;
        j++;
    }
    printf("trailing zeros:  %d", num);
}