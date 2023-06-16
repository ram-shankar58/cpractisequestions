#include <stdio.h>
void main(){
    float bp;
    scanf("%f",&bp);
    printf("%f",bp);
    float da=0.88*bp;
    float hra=0.08*bp;
    float ca=1000;
    float ins=2000;
    float pf=0.1*bp;
    float gp=bp+da+hra+ca;
    float ded=ins+pf;
    float np=gp-ded;
    printf("\n%f",np);
}
