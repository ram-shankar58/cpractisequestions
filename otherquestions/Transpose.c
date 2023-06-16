//Transpose of a matrix
#include <stdio.h>
int tran(int mat[64][64],int n1,int n2){
    int b[n1][n2];
    int i;
    int j;
    for (i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            b[i][j]=mat[j][i];
        }
    }
    printf ("Transpose matrix:\n");
     for (i=0;i<n2;i++){
        for(j=0;j<n1;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
     }
    
}

int main(){
    int n1;
    scanf("%d",&n1);
    int n2;
    scanf("%d",&n2);
    int mat[64][64];
    int i,j;
    for (i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    tran(mat,n1,n2);
    
}
