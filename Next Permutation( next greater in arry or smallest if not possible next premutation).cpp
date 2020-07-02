/*
Implement the next permutation, 
which rearranges numbers into the numerically next greater permutation of numbers.
 If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

For example:
1,2,3 ? 1,3,2
3,2,1 ? 1,2,3

*/
vector<int> Solution::nextPermutation(vector<int> &A) {
       int dip=-1;
       int dip_index=-1;
       for(int i=A.size()-1;i>0;i--)//find the dip point and swap with the greater element than dip form the last and then reverse from dip_index+1 to end;
       {
           if(A[i]>=A[i-1])
           {
               dip=A[i-1];
               dip_index=i-1;
               break;
           }
       }
       if(dip_index!=-1)
       {
       for(int i=A.size()-1;i>=0;i--)
       {
           if(A[i]>=dip)
           {
               swap(A[i],A[dip_index]);
               reverse(A.begin()+(dip_index+1),A.end());
               return A;
           }
       }
       }
       reverse(A.begin(),A.end());
           return A;
    
}

       
