#include <stdio.h> //Used to include basic c library files

void main()        // Used to execute the C application
{
    // declaring and defining the array variables
    int a[5] = {100, 101, 102, 103, 104};
    int b[5] = {105, 106, 107, 108, 109};
    // displaying the output
    printf("%d\n", a[100]); // array index doesn't exist
    // and another element
    printf("%c\n", b[700]); // prints c instead of d. AND array index doesn't exist.
}