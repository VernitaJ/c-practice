#include <stdio.h>
#include <string.h>

int main() {
    long input;  // at least 32 bits
    unsigned long number;
    int i;

    printf("Enter an integer: ");
    if (scanf("%ld", &input) != 1) 
        return 1;
    /* copy the bit pattern to an unsigned long */
    memcpy(&number, &input, sizeof number);
    for (i = 32; i-- > 0;) {
        if (i > 0 && (i & 7) == 0)
            putchar(' ');
        putchar('0' + (int)((number >> i) & 1));
    }
    putchar('\n');
    return 0;
}