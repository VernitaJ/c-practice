#include <stdio.h>
#include <string.h>
 

/* Driver program to test above functions */
int main()
{
    char str[] = "abcd";
    int n = strlen(str);
    //printf("%s\n", str);
    permute(str, 0, n-1);
    return 0;
}

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
void permute(char *a, int l, int r)
{
int i;
if (l == r)
    printf("%s\n", a);
else
{
    for (i = l; i <= r; i++)
    {
        swap((a+l), (a+i));
        permute(a, l+1, r);
        swap((a+l), (a+i)); //backtrack
    }
}
}
