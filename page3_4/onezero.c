#include <stdio.h>
#include <limits.h>

int CountOnesFromInteger(unsigned int);
int main()
{
    int inputValue;
    short unsigned int onesOfValue;
    printf("Please Enter value (between 0 to 4,294,967,295) : ");
    scanf("%d", &inputValue);
    onesOfValue = CountOnesFromInteger(inputValue);

    printf("\nThe Number has \"%d\" 1's and \"%zu\" 0's", onesOfValue, 8 - onesOfValue);
    return 0;
}

int CountOnesFromInteger(unsigned int value)
{
    int count;
    for (count = 0; value != 0; count++)
    {
        value &= value - 1;
    }
    return count;
}