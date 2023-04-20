#include <stdio.h>
int func(int a[64][64], int n, int len);
static int sum2=0;
int main() {
    int inp;
    int c=0;
    scanf("%d",&inp);
    int inp2 = inp;
    int array[64][64];
    for (int i=0;i<inp2;i++) {
        for (int j=0;j<inp2;j++) {
            scanf("%d",&array[i][j]);
            c++;
        }
    }
    func(array,inp,c);
    if (sum2 != 0) printf("%d",sum2);
}
int func(int a[64][64],int n,int len) {
    int sum1=0;
    // int sum2=0;
    for (int i=0;i<len;i++) {
        for (int j=0;j<len;j++) {
            if (n%2!=0) {
                sum1 += a[i][j];
            } // in case input number is odd 
            
            else if (n%2==0) { // in case input number is even
                if (a[i][j]%2==0) sum2 += a[i][j];
            }
        }
    }
    if (n%2!=0) printf("%d\n",sum1);
    else {
        return 0;
    }
}
