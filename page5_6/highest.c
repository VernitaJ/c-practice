#include <stdio.h>

void highest(int);
int main()
{
    int input;
    printf("What's the number: ");
    scanf("%d", &input);
    highest(input);
    return 0;
}

void highest(int input)
{   
    int highest;
    for (int i = 0; i < 8; i++)
    {
        if ((input >> i) & 1)
        {
            highest = i;
        }
    }
    printf("highest: %d", highest);
    printf("\n0 : %d", (7 >> 0) & 1);
    printf("\n1 : %d", (7 >> 1) & 1);
    printf("\n2 : %d", (7 >> 2) & 1);
    printf("\n3 : %d", (7 >> 3) & 1);
    printf("\n4 : %d", (7 >> 4) & 1);
}