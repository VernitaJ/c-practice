#include <stdlib.h>
#include <stdio.h>

struct pos {
  int x, y;
};

int sum(int p[], int count)
{
  int total = 0;

  for (int i = 0; i < count; i++)
    total += p[i];

  return total;
}

void p_l(struct pos p)
{
  printf("(%d,%d)\n", p.x, p.y);
}
void f()
{
  printf("atexit print\n");
}

int main(int argc, char const *argv[])
{
  int *ptr;
  ptr = (int[]){1, 2, 3, 4};
  int (*pf)(const char *, ...) = printf;
  pf("hello world\n");

  p_l((struct pos){.x = 10, .y = 11});

  atexit(f);
  int s1 = sum(ptr, 4);
  int s2 = sum((int[]){1, 2, 3, 4}, 4);
  printf("sum of s1 is: %d\n", s1);
  printf("sum of s2 is: %d\n", s2);

  int x = 3490;
  printf("%d\n", x);           // 3490 (variable)
  printf("%d\n", 3490);        // 3490 (constant)
  printf("%d\n", (int){3490}); // 3490 (unnamed object)


  return 0;
}