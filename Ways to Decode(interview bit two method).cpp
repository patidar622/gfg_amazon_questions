/*
Problem Description

A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
Given an encoded message A containing digits, determine the total number of ways to decode it modulo 109 + 7.



Problem Constraints
1 <= |A| <= 105



Input Format
The first and the only argument is a string A.



Output Format
Return a single integer denoting the total number of ways to decode it modulo 109 + 7.



Example Input
Input 1:

 A = "8"
Input 2:

 A = "12"


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 Given encoded message "8", it could be decoded as only "H" (8).
 The number of ways decoding "8" is 1.
Explanation 2:

 Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).
 The number of ways decoding "12" is 2.
*/
//unordered_map<string,int>m1;
/*vector<vector<int>>dp;
long long int m=1000000007;
int find_solution(string s,int i1,int j1)
{
    if(s.size()==1 && stoi(s)==0)
    return 0;
    if(s.size()==1)
    return 1;
   if(s.size()==2 && stoi(s)>10 &&  stoi(s)!=20 && stoi(s)<=26)
   return 2;
   if(s.size()==2 && stoi(s)>26)
   return 1;
   if(dp[i1][j1]!=-1)
   return dp[i1][j1];
   
   long long int ans=0;
   for(int i=1;i<s.size();i++)
   {
       ans=max(ans,(find_solution(s.substr(0,i),i1,i1+i-1)%m)*(find_solution(s.substr(i,s.size()-i),i1+i,j1)%m)%m);
   }
   return dp[i1][j1]=ans%m;
}
*/
int Solution::numDecodings(string A) {
  //this method o(n) and 0(1) space and same as fibonacci series solution
  
    if(A[0]=='0')
    return 0;
  long long int m=1000000007;
  int a=1,b=1;
  for(int i=1;i<A.size();i++)
  {
      int t=0;
      if(A[i]>'0')
      t=b%m;
      if((A[i-1]=='1') || (A[i-1]=='2' && A[i]<'7'))
      {
          t=(t+a)%m;}
          a=b%m;
          b=t%m;
  }
  return b%m;
  
  /* //this method gives tle because time comp o(n^2)  
    dp.clear();
    dp.resize(A.size()+1,vector<int>(A.size()+1,-1));
    return find_solution(A,0,A.size()-1)%m;*/
}

