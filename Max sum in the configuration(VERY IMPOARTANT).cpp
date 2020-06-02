/*
Given an array(0-based indexing), you have to find the max sum of i*A[i] where A[i] is the element at index i in the array. The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.
User Task:
 Your task is to complete the function max_sum which takes two arguments which is the array A [ ] and its size and returns an integer value denoting the required max sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/
int max_sum(int A[],int N)
{
      int mx_sum=0,max1=A[0];
      for(int i=1;i<N;i++)
      {
              max1+=A[i];
              mx_sum+=i*A[i];
      }
      int ans=mx_sum;
      for(int i=1;i<N;i++)
      {
          mx_sum=mx_sum+max1-(N*A[N-i]);
          ans=max(ans,mx_sum);
      }
      return ans;
}
