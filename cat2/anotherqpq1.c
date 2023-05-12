/*
Jack is  a sports teacher at school He makes games not only to make students fit but also smart.
He lined up all the N number of classes of students in his class. At each position he has fixed a board with integer number printed on it.
Each number is unique and in exactly the range of N. Let us say there are 10 students, the boards will be printed with numers from 1 to 10 in a random order
given by the sequence A[]. As a rule all studets wear a jersey with their number printed on it. Each unique jersey is a team
Now in beginning, all students will stand as per increasing order of jersey number, from left to right. The only difference will be their respective board
number which is placed at their respectie location. The board location is fixed and cannot be changed


*/

//What a dumb question blyaat?!


#include <stdio.h>
#include <stdlib.h>

void arrange(int *A, int n)
{
    int i, j, temp;

    // Traverse the array
    for(i=0;i<n;i++)
    {
        // Find the position of the minimum element in the unsorted part of the array
        int min_idx=i;
        for(j=i+1;j<n;j++)
        {
            if(*(A+j) < *(A+min_idx))
                min_idx=j;
        }

        // Swap the current element with the minimum element
        temp=*(A+i);
        *(A+i)=*(A+min_idx);
        *(A+min_idx)=temp;
    }
}

int main()
{
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for the board number array
    int *A = (int*)malloc(n * sizeof(int));


    printf("Enter the board numbers:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", (A+i));
    }

    // Sort the board numbers
    arrange(A, n);

    
    printf("Team order:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ", i+1);
    }
    printf("\n");


    return 0;
}
