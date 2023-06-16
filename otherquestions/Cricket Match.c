/*
CODECHEF-Q2
There is a cricket match in Chefland. Chef's team requires 
�
N runs to win in 
�
M overs.

Given that 
1
1 over consists of 
6
6 balls and a player can score a maximum of 
6
6 runs in a ball, find whether Chef's team can win.

Input Format
The first line of input will contain a single integer 
�
T, denoting the number of test cases.
Each test case consists of two space-separated integers 
�
N and 
�
M — the number of runs required to win the game and the remaining number of overs.
Output Format
For each test case, output on a new line, YES, if Chef's team can win the game. Otherwise, output NO.

You can print each character in uppercase or lowercase. For example NO, no, No, and nO are all considered identical.

Constraints
1
≤
�
≤
1000
1≤T≤1000
1
≤
�
≤
1000
1≤N≤1000
1
≤
�
≤
100
1≤M≤100
Sample 1:
Input
Output
4
500 20
100 2
30 1
216 6
YES
NO
YES
YES
Explanation:
Test case 
1
1: Chef's team requires 
500
500 runs to win. If they hit 
6
6 runs on every ball for 
13
13 overs, they will score 
6
⋅
6
⋅
13
=
468
6⋅6⋅13=468 runs.
In the 
1
4
�
ℎ
14 
th
  over they can hit 
6
6 runs in the first five balls and 
2
2 runs in the sixth ball to get a total of 
468
+
6
⋅
5
+
2
=
500
468+6⋅5+2=500 runs.
Thus, Chef's team can win the game.

Test case 
2
2: Since 
100
100 is greater than the maximum runs that can be scored 
2
2 overs, it is not possible for Chef's team to win the game.

Test case 
3
3: Since 
30
30 is less than the maximum runs that can be scored in 
1
1 over, it is possible for Chef's team to win the game.

Test case 
4
4: Since 
216
216 is equal to the maximum runs that can be scored in 
6
6 overs, it is possible for Chef's team to win the game.
*/
#include <stdio.h>

int main(void) {
	int N,M;
	int T;
	scanf("%d",&T);
	int i;
	for(i=0;i<T;i++){
	    scanf("%d %d",&N,&M);
	    if ((36*M)>=N){
	        printf("YES\n");
	    }
	    else{
	        printf("NO\n");
	    }
	    
	}
	return 0;
}
