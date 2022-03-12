#include <stdio.h>
int main() {
  const char *s = " 13/6  \n";
  int a,b;
  sscanf(s, "%d/%d", &a, &b);
  printf("%d frac %d\n", a, b);
  return 0;
}