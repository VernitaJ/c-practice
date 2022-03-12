#include <stdio.h>
#include <stdlib.h>

int anagram(char[], char[]);

int main(int argc, char const *argv[])
{
    char a[10], b[10];
    // first = malloc(4);
    // second = malloc(4);
    printf("Test Data:\n%s", "Input the first string: ");
    gets(a);
    printf("\nInput the second string: ");
    gets(b);

    int success = anagram(a, b);
    if (success)
    {
        printf("%s and %s are anagrams", a, b);
    } else printf("%s and %s are not anagrams", a, b);
    return 0;
}

int anagram(char a[], char b[])
{
   int first[26] = {0}, second[26] = {0}, c=0;

  // Calculating frequency of characters of the first string

  while (a[c] != '\0') {
    first[a[c]-'a']++;
    c++;
  }
  printf("%d", first[a[0]-'a']);

  c = 0;

  while (b[c] != '\0') {
    second[b[c]-'a']++;
    c++;
  }

  // Comparing the frequency of characters

  for (c = 0; c < 26; c++)
    if (first[c] != second[c])
      return 0;

  return 1;
}