#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void count(char *);
int main(int argc, char const *argv[])
{
    char *str = NULL;
    str = malloc(100);
    printf("Test Data:\n%s", "Input a string: ");
    scanf("%[^\n]", str);
    count(str);
    free(str);
    return 0;
}

void count(char *str)
{
    int vowels;
    int consonant, vowel = 0;
    while (*str != '\0') 
    {
        char c = *str;
        if (isalpha(c))
        {
            vowels = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                      c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
            if (vowels)
            {
                vowel++;
            }
            else
                consonant++;
        }

        str++;
    }
    printf("Number of vowels: %d\n", vowel);
    printf("Number of consonants: %d\n", consonant);
}