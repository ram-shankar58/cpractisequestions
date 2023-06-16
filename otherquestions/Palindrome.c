#include <stdio.h>
double pow(double a, double b) {
  int i=0,res = 1;
  for (i=0;i<b;i++) res*=a;
  return res;
}
void main() {
  int num;
  int t1,t2;
  int r;
  int x;
  int cnt;
  scanf("%d",&num);
  t1 = num;
  cnt = 0;
  r = 0;
  while (t1>=1) {
    cnt += 1;
    t1/=10;
  }
  t2 = num;
  while (cnt > 0) {
    x = t2%10;
    r += x * pow(10,cnt-1);
    t2 /= 10;
    cnt--;
  }
  (r == num) ? printf("%d is a palindrome",r) : printf("%d is not a palindrome",r);
}
