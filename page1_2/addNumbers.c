#include <stdio.h>
#include <stdlib.h>

void addNumbers(int *, int *);

int main(int argc, char const *argv[])
{
    int *first, *second;
    printf("Test Data:\n%s","Input the first number: ");
    first = malloc(5);
    scanf("%5d", first);

    printf("%s", "Input the second number: ");
    second = malloc(5);
    scanf("%5d", second);

    addNumbers(first, second);
    free(first);
    free(second);
    return 0;
}

void addNumbers(int *first, int *second){
    printf("The sum of the entered numbers is: %d", *first+*second);
}