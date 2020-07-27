/*

Problem Description

Given an array of integers A of size N in which ith element is the price of the stock on day i.

You can complete atmost B transactions.

Find the maximum profit you can achieve.

NOTE: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
Output Format
Return the maximum profit you can achieve by doing atmost B transactions.



Example Input
Input 1:

 A = [2, 4, 1]
 B = 2
Input 2:

 A = [3, 2, 6, 5, 0, 3]
 B = 2
*/
vector<vector<int>>dp;
int find_solution(vector<int>& A,int i,int B)
{
    if(B==0)
    return 0;
    if(i>=A.size())
    return 0;
    
    if(dp[i][B]!=-1)
    return dp[i][B];
    int n1=0,ans=0;
    for(int j=i+1;j<A.size();j++){
        
        n1+=A[j]-A[j-1];
        
        if(n1<=0)
        {
            break;
        }
        ans=max(ans,n1+find_solution(A,j+1,B-1));
    }
    ans=max(ans,find_solution(A,i+1,B));
    return dp[i][B]=ans;
}
int Solution::solve(vector<int> &A, int B) {
    dp.clear();
    int n=A.size();
    B=min(B,n);
    dp.resize(A.size()+1,vector<int>(B+1,-1));
    
    int ans=0;
       ans=max(ans,find_solution(A,0,B));
    return ans;
}

