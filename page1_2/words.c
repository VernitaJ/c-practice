#include <stdio.h>

int main(int argc, char const *argv[])
{
    getAmount();
    return 0;
}

void getAmount()
{
    long ctr_char, ctr_word, ctr_line;
    int c;
    int flag;

    ctr_char = 0;
    flag = ctr_line = ctr_word = 0;
    printf("Input a string and get number of characters, words and lines:\n");
    while ((c = getchar()) != EOF)
    {
        ++ctr_char;
        if (c == ' ' || c == '\t')
        {
            flag = 0;
        }
        else if (c == '\n')
        {
            ++ctr_line;
            flag = 0;
        }
        else
        {
            if (flag == 0)
            {
                ++ctr_word;
            }
            flag = 1;
        }
    }
    printf("\nNumber of Characters = %ld", ctr_char);
    printf("\nNumber of words = %d", ctr_word);
    printf("\nNumber of lines = %d", ctr_line);
}
