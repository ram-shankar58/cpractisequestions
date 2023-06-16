#include <stdio.h>

int power(int a, int b) {
  int i;
  int result = 1;
  for (i=0;i<b;i++){
    result = result*a;
  }
  return result;
}

int length(int n) {
  int cnt=0;
  int t=n;
  while (t>0) {
    cnt += 1;
    t /= 10;
  }
  return cnt;
}

int isArmstrong(int n) {
  int t = n;
  int p=0;
  int result=0;
  int l = length(n);
  int x;
  while (t>0) {
    x = t%10;
    p += power(x,l);
    t /= 10;
  }
  if (p==n) {
    result = 1;
  }
  else {
    result = 0;
  }
  return result;
}

int main() {
  int n;
  int amc=0,namc=0;
  do {
    scanf("%d",&n);
    if (isArmstrong(n)==1) amc += 1;
    else namc += 1;
  } while (n != -1);

  printf("Armstrong: %d\n",amc);
  printf("Non Armstrong: %d",namc-1);
}
