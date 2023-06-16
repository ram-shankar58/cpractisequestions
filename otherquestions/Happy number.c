#include <stdio.h>

int happy(int n) {
  int t=n;
  int x;
  int h=0;
  while (t > 0) {
    x = t%10;
    h += x*x;
    t /= 10;
  }
  return h;
}

int main() {
  int n;
  printf("Enter n: ");
  scanf("%d",&n);
  int n1 = n;
  while (happy(n1) >= 10 || happy(n1) < 0) {
    n1 = happy(n1);
    /* printf("%d\n",n1); */
  }

  (happy(n1)==1) ? printf("%d is a Happy number",n) : printf("%d is not a Happy number",n);

  return 0;
}
