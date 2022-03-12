#include <stdio.h>
#include <stdlib.h>

int anagram(char**, char**);

int main(int argc, char const *argv[])
{
    char *first[8], *second[8];
    // first = malloc(4);
    // second = malloc(4);
    printf("Test Data:\n%s", "Input the first string: ");
    gets(first);
    printf("\nInput the second string: ");
    gets(second);
    printf("\nOutput the first string: %s\n", first);
    int success = anagram(first, second);
    // if (success)
    // {
    //     printf("%s and %s are anagrams", a, b);
    // }
    // else
    //     printf("%s and %s are not anagrams", a, b);
    // return 0;
}

int anagram(char **a, char **b)
{
    int **ptr = *b;
    int **ptra = *a;
    int contains = 0;
    printf("ptr: %d, *ptr: %c, b: %d, *b: %c, *ptra : %c\n", ptr, *ptr, b, *b, *ptra);
    for (int i = 0; i < 1; i++)
    {
        ptra++;
        printf("%c", *ptra);
    }
    // while (*ptra != '\0')
    // {
    //     printf("%c", *ptr);
    //     while(*ptr != '\0')
    //     {
    //         if (*ptr == *a){
    //             contains = 1;
    //         } else contains = 0;
    //         ptr++;
    //     }
    //     ptra++;
    //     *ptr = &(*b);
    // }
    if (contains == 0)
    {
        printf("%s and %s are not anagrams", a, b);
    }
}