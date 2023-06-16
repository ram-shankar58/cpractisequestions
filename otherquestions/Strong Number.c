// Sum of factorial of digits = n
// 145 = 1! + 4! + 5!
#include <stdio.h>

int factorial(int num) {
  int i,fact=1;
  for (i=1;i<=n;i++){
    fact *= i;
  }
  return fact;
}

int main() {
  int a,b;
  printf("\nEnter lower, upper limits: ");
  scanf("%d,%d",&a,&b);
  int i;
  int temp;
  for (i=a;i<=b;i++) {
    int s=0;
    temp = i;
    while (temp>0) {
      s += factorial(temp%10);
      temp /= 10;
    }
    if (s==i) printf("%d is a strong number\n",i);
  }
  return 0;
}
