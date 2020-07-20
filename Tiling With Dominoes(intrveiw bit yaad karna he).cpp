/*
Problem Description

Given an integer A you have to find the number of ways to fill a 3 x A board with 2 x 1 dominoes.

Return the answer modulo 109 + 7 .

NOTE:

See the sample explanation for better understanding.


Problem Constraints
1 <= A <= 105



Input Format
First and only argument is an integer A.



Output Format
Return an integer denoting the number of ways to fill a 3 x A board with 2 x 1 dominoes with modulo 109 + 7.



Example Input
Input 1:

 2
Input 2:

 1


Example Output
Output 1:

 3
Output 2:

 0


Example Explanation
Explanation 1:

 Following are all the 3 possible ways to fill up a 3 x 2 board.
 
Explanation 2:

 Not a even a single way exists to completely fill the grid of size 3 x 1.


*/
int Solution::solve(int A) {
   long long dp[A+1],i,j,mod=1e9+7;
    dp[0]=0;dp[1]=0;
    for(i=2;i<A+1;i++)
    {
        if(i%2!=0)
        {
            dp[i]=0;
            continue;
        }
        if(i==2)
        dp[i]=3;
        else if(i==4)
        dp[i]=11;
        else
        dp[i]=(dp[i-2]*3+(dp[i-2]-dp[i-4])+mod)%mod;
    }
    return dp[A];
    
    
}

