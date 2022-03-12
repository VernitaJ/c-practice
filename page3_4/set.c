#include <stdio.h>

void convert(int, int);
int main(int argc, char const *argv[])
{
    int num, which;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter nth bit number: ");
    scanf("%d", &which);
    convert(num, which);
    return 0;
}

void convert(int d, int which)
{
    int size = 8; // set size to the number of bits returned from get_byte()
    int binary[size];       // create an array of integers the size of the required bits
    for (int i = 0; i < size; i++)
    {                                   // loop over each number in the array of bits
        binary[i] = (char)(d >> i) & 1; // we shift the decimal down based on the ith digit of the binary representation and check whether that digit should be a 1 or a 0
    }
    for (int i = size - 1; i >= 0; i--)
    {                            // for each number in the array in reverse order
        printf("%d", binary[i]); // print every element
    }
    printf("\n"); // next line
    if (binary[which-1] == 1){
        printf("%d bit of %d is set (1)", which, d);
    } else printf("%d bit of %d is not set", which, d);    
    
}