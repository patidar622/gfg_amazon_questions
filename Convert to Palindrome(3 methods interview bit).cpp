/*
Problem Description

Given a string A consisting only of lowercase characters,
 we need to check whether it is possible to make this string a palindrome after removing exactly one character from this.

If it is possible then return 1 else return 0.

*/
int find_solution(string A,int i,int j,int count)
{
    if(count>=2)
    return 0;
    if(count==1 && i>=j)
    return 1;
    if(A[i]==A[j])
    return find_solution(A,i+1,j-1,count);
    else
    return find_solution(A,i+1,j,count+1)||find_solution(A,i,j-1,count+1);
}
int is_palindrome(string A,int i,int j)
{
    while(i<j)
    {
        if(A[i]!=A[j])
        return 0;
        i++;
        j--;
    }
    return 1;
}
int Solution::solve(string A) {
    //return find_solution(A,0,A.size()-1,0);
    int i=0,j=A.size()-1;
    while(i<=j)
    {
        if(A[i]==A[j])
        {
            i++;
            j--;
            continue;
        }
        else
        {
            return is_palindrome(A,i+1,j)||is_palindrome(A,i,j-1);
        }
    }
    return 1;
   /*int n=A.size();
   vector<vector<int>>dp(A.size()+1,vector<int>(A.size()+1,0));
   
   string s=A;
   reverse(s.begin(),s.end());
   for(int i=0;i<=A.size();i++)
   {
       for(int j=0;j<=s.size();j++)
       {
           if(i==0 || j==0)
           {
               dp[i][j]=0;
           }
          else if(A[i-1]==s[j-1])
           {
               dp[i][j]=1+dp[i-1][j-1];
           }
           else
           dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
       }
   }
   int n1=dp[n][n];
   if(n-n1<=1)
   return 1;
   
   return 0;
    */
}

