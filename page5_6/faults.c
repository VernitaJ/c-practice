#include <stdio.h>

#define MAX_SIZE 5 // Maximum size of the array

int main()
{
    int arr[MAX_SIZE]; // Declares an array size //CHANGE - THERE SHOULDN'T BE A CONSTANT
    int i, num;
    // Enter size of array
    printf("Enter size of the array: ");
    scanf("%d", &num);
    if (num < 1)
    {
        printf("Number has to be larger than 0");
        return 0;
    }
    // Reading elements of array
    printf("Enter elements in array: \n");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]); 
    }
    printf("\nAll negative elements in array are: ");
    for (i = 0; i < num; ++i)
    {
        // Printing negative elements
        if (arr[i] < 0)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}