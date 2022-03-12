#include <stdio.h>

void evenorodd(int);

int main()
{
    int input = 0;
    printf("Input a number: ");
    scanf("%d", &input);
    evenorodd(input);
    return 0;
}

void evenorodd(int input)
{

    if ((input ^ 1) == input +1)
    { 
        printf("%d: number is even");
    } else printf("number is odd");
}