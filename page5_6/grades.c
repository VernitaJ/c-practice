#include <stdio.h>

int main()
{
    int arr[5];
    printf("Enter 5 grades for the student:\n");

    int total = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("Grade %d : ", i+1);
        scanf("%d", &arr[i]);
        total += arr[i];
    }

    int percentage = total/5;
    printf("Percentage = %d\n",percentage);
    if (percentage >= 90)
        printf("Grade A");
    else if (percentage >= 80)
        printf("Grade B");
    else if (percentage >= 70)
        printf("Grade C");
    else if (percentage >= 60)
        printf("Grade D");
    else if (percentage >= 50)
        printf("Grade E");
    else printf("Grade F");
    return 0;

}
