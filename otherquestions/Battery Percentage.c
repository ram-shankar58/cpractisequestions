/*
CODECHEF-Q3
Chef's phone has a battery level of 
�
N percent.
Each minute:

If the phone is on charging, the battery level increases by 
2
%
2%.
Otherwise, the battery level decreases by 
3
%
3%.
Find the minimum time in which Chef can make the battery level reach exactly 
50
%
50%.
Note that the battery level should always lie in the range 
0
0 to 
100
100 (both included).

Input Format
The first line of input will contain a single integer 
�
T, denoting the number of test cases.
Each test case consists of single lines of input 
�
N - the current battery level of Chef's phone.
Output Format
For each test case, output on a new line the minimum time in which Chef can make the battery level reach exactly 
50
%
50%.

Constraints
1
≤
�
≤
1000
1≤T≤1000
0
≤
�
≤
100
0≤N≤100
Sample 1:
Input
Output
4
51
50
23
0
2
0
16
25
Explanation:
Test case 
1
1: Chef can use his phone for 
1
1 minute. Thus, the battery drops to 
48
%
48%.
Then, he can charge it for 
1
1 minute. Thus, the battery reaches exactly 
50
%
50%.

Test case 
2
2: The battery level is already at 
50
%
50%.

Test case 
3
3: Chef can charge the battery for 
15
15 minutes and use it for 
1
1 minute.
Thus, after 
16
16 minutes, the battery will be 
50
%
50% .

Test case 
4
4: Chef can charge the battery for 
25
25 minutes to reach the battery level of 
50
%
50%.
*/
#include <stdio.h>

int main(void) {
	int T,N;
	scanf("%d",&T);
	int i;
	for(i=0;i<T;i++){
	    int t=0;
	    scanf("%d",&N);
	    if (N==50){
	        t+=0;
	    }
	    while(N!=50){
	        if(N>50){
	            N-=3;
	        }
	        else{
	            N+=2;
	        }
	        t++;
	    }
	    printf("%d\n",t);
	}
	return 0;
}
