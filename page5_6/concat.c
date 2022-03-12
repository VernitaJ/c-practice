#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char* first = malloc(20);
    char* second = malloc(20);
    printf("First string: ");
    scanf("%19[^\n]", first);
    printf("Second string: ");
    scanf(" %19[^\n]", second);
    int length1 = strlen(first);
    int length2 = strlen(second);
    char * p = (char*)malloc( length1 + length2 + 2);
    
    int i = 0;
    for (; i < length1; i++)
    {
        p[i] = first[i];
    }
    p[i] = ' ';
    int j = length1+1;
    for (int i = 0;  i < length2; i++)
    {
        p[j] = second[i];
        j++;
    }
    p[j] = '.';
    printf("%s", p);
    return 0;
}
