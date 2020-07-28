/*
Problem Description

You are given A eggs, and you have access to a building with B floors from 1 to B.

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor C with 0 <= C <= B such that any egg dropped at a floor higher than C will break, and any egg dropped at or below floor C will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= B).

Your goal is to know with certainty what the value of C is.

What is the minimum number of moves that you need to know with certainty what C is, regardless of the initial value of C



Problem Constraints
1 <= A <= 100
1 <= B <= 104


Input Format
First Argument is an integer A denoting number of eggs.

Second Argument is an integer B denoting number of floors.



Output Format
Return an integer denoting the Minimum number of moves.



Example Input
Input 1:

 A = 1
 B = 2
Input 2:

 A = 2
 B = 10


Example Output
Output 1:

 2
Output 2:

 4 


Example Explanation
Explanation 1:

 Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
 Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
 If it didn't break, then we know with certainty F = 2.
 Hence, we needed 2 moves in the worst case to know what F is with certainty.


*/
vector<vector<int>>dp;
int find_solution(int A,int B)
{
    if(A==1)
    return B;
    if(B==1 || B==0)
    return B;
    
    if(dp[A][B]!=-1)
    return dp[A][B];
    int temp=0,ans=INT_MAX;
    int low=1,high=B;
    while(low+1<high)
    {
        int mid=low+(high-low)/2;
        int i1=find_solution(A-1,mid-1);
        int i2=find_solution(A,B-mid);
        
        if(i1<i2)
        low=mid;
        else if(i1>i2)
        high=mid;
        else
        low=high=mid;
    }
    ans=1+min(max(find_solution(A-1,low-1),find_solution(A,B-low)),max(find_solution(A-1,high-1),find_solution(A,B-high)));
    return dp[A][B]=ans;
}
int Solution::solve(int A, int B) {
    dp.clear();
    dp.resize(A+1,vector<int>(B+1,-1));
    return find_solution(A,B);
}

