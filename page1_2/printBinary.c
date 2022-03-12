#include <stdint.h>
#include <stdio.h>

void outputBinary(uint32_t);
int main(int argc, char const *argv[])
{
    int num = atoi(argv[1]);
    uint32_t large = (long) num;
    printf("%s\n", argv[1]);
    outputBinary(large);
    uint32_t check = 32;
    return 0;
}

void outputBinary(uint32_t x){
  char binary[35];
   for (int i = 0; i < 35; i++)
  {                    
    if (i == 8 || i == 17 || i == 26){ // loop over each number in the array of bits
    binary[i]= '.';
    } else {    
    binary[i] = (char)(x >> i) & 1; // we shift the decimal down based on the ith digit of the binary representation and check whether that digit should be a 1 or a 0
    }
  }
  for (int i = 35 - 1; i >= 0; i--)// for each number in the array in reverse order
  {                          
  if (i == 8 || i == 17 || i == 26){
      printf("%c", binary[i]);
  } else printf("i:%d, %d ", i, binary[i]); // print every element
  }
  printf("\n"); // next line
}