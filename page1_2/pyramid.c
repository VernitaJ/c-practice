#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    char arr[13] = {'t', 's', 'e', 'b', 's', 'i', 'C', 'i', 's', 'b', 'e', 's', 't'};
    printArr(arr);
    return 0;
}

void printArr(char arr[])
{
    int current = 6;
    int space = 2;
    for (int i = 0; i < 7; i++)
    {
        if (current == 6)
        {
            for (int j = 0; j < current; j++){
            printf("%s", "   ");
            }
            printf(" %c\n", arr[current]);
        } else if (current == 0){
            for (int j = 0; j < 13; j++){
                printf("%c  ", arr[j]);
            }
        }
         else {
            for (int k = current; k > 0; k--){
                printf("%s", "   ");
            }
            printf("%c", arr[current]);
            for (int j = space; j > 0; j--){
                printf("%s", "   ");
            }
            printf("%c\n", arr[current]);
            space+=2;
        }
        current--;
    }
}