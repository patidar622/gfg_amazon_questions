/*
You are given an array A consisting of strings made up of the letters ‘a’ and ‘b’ only.
Each string goes through a number of operations, where:

1.	At time 1, you circularly rotate each string by 1 letter.
2.	At time 2, you circularly rotate the new rotated strings by 2 letters.
3.	At time 3, you circularly rotate the new rotated strings by 3 letters.
4.	At time i, you circularly rotate the new rotated strings by i % length(string) letters.

Eg: String is "abaa"

1.	At time 1, string is "baaa", as 1 letter is circularly rotated to the back
2.	At time 2, string is "aaba", as 2 letters of the string "baaa" is circularly rotated to the back
3.	At time 3, string is "aaab", as 3 letters of the string "aaba" is circularly rotated to the back
4.	At time 4, string is again "aaab", as 4 letters of the string "aaab" is circularly rotated to the back
5.	At time 5, string is "aaba", as 1 letters of the string "aaab" is circularly rotated to the back
After some units of time, a string becomes equal to it’s original self.
Once a string becomes equal to itself, it’s letters start to rotate from the first letter again (process resets). 
So, if a string takes t time to get back to the original, at time t+1 one letter will be rotated and the string will 
be it’s original self at 2t time.
You have to find the minimum time, where maximum number of strings are equal to their original self.
As this time can be very large, give the answer modulo 109+7.

Note: Your solution will run on multiple test cases so do clear global variables after using them.
Input:

A: Array of strings.
Output:

Minimum time, where maximum number of strings are equal to their original self.
Constraints:

1 <= size(A) <= 10^5
1 <= size of each string in A <= 10^5
Each string consists of only characters 'a' and 'b'
Summation of length of all strings <= 10^7
Example:

Input

A: [a,ababa,aba]
Output:4

String 'a' is it's original self at time 1, 2, 3 and 4.
String 'ababa' is it's original self only at time 4. (ababa => babaa => baaba => babaa => ababa)
String 'aba' is it's original self at time 2 and 4. (aba => baa => aba)

Hence, 3 strings are their original self at time 4.
*/
//this question can also be solved with kmp algorithm
int Solution::solve(vector<string> &A) {
    long long int m=1000000007;
   long long  int ans=1;
   vector<int>vis(A.size());
    for(int i=0;i<A.size();i++)
    {
       long long  int n1=1;
       string s=A[i];
 long long  int s2=s.size();
    long long int count=0;
    if(s2<=1)
   vis[i]=1;
   else{
    while(1)
    {
        count=(n1*(n1+1))/2;
        if(count%s2==0)
       { vis[i]=n1;
        break;}
        n1++;
    }
    }
    }
   
   for(long long int i=0;i<A.size();i++)
   {
       for(long long int j=i+1;j<A.size() && vis[i]!=1 ;j++)
       {
           vis[j]=vis[j]/__gcd(vis[i],vis[j]);
       }
       ans=(long long)((ans%m*(vis[i])%m)%m);
   }
    
    return (int)ans%m;
}


