/*
Problem Description

Given a binary array A and a number B, we need to find length of the longest subsegment of ‘1’s possible by changing at most B ‘0’s.



Problem Constraints
1 <= N, B <= 105

A[i]=0 or A[i]=1



Input Format
First argument is an binary array A.

Second argument is an integer B.



Output Format
Return a single integer denoting the length of the longest subsegment of ‘1’s possible by changing at most B ‘0’s.
Example Input
Input 1:

 A = [1, 0, 0, 1, 1, 0, 1]
 B = 1
Input 2:

 A = [1, 0, 0, 1, 0, 1, 0, 1, 0, 1]
 B = 2


Example Output
Output 1:

 4
Output 2:

 5
*/
int Solution::solve(vector<int> &A, int B) {
  int i=0,j=0,count=0,n=A.size(),ans=INT_MIN;
  while(j<A.size())
  {
      if(A[j]==0)
      count++;
      
      while(count>B)
      {
          
          if(A[i++]==0)
          count--;
      }
      ans=max(ans,j-i+1);
      j++;
  }
  return ans;
  
  
  
  // this gives tle because o(n2) approch he
  
   /* int i=0;
    int ans=INT_MIN;
    while(i<A.size())
    {
        int j=i,k=B;
        while(j<A.size() && (k>0  || A[j]==1))
        {
            if(A[j]==1)
            j++;
            else if(k>0)
            {
                k--;
                j++;
            }
            else
            break;
        }
        ans=max(ans,j-i);
        i++;
    }
    return ans;*/
}



