/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
You need to do this in place.
Note that if you end up using an additional array, you will only receive partial score.
Example:
If the array is
[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:
[
    [3, 1],
    [4, 2]
]
*/
/*
the main logic is that the required matrix is obtainted in two ways 
  1. we have to find the in-place transpose of matrix 
  2. then reverse the each matrix
  
  eg:[[1,2,3]
      [4,5,6]
      [7,8,9] 
      ]
      // transpose
      [
	  [1,4,7]
	  [2,5,8]
	  [3,6,9]
	  ]
	  //reverse
	  [
	  [7,4,1]
	  [8,5,2]
	  [9,6,3]
	  ]
*/
void Solution::rotate(vector<vector<int> > &A) {
   for(int i=1;i<A.size();i++)
   {
       for(int j=0;j<i;j++)
       {
           swap(A[i][j],A[j][i]);
       }
   }
   for(int i=0;i<A.size();i++)
   {
       reverse(A[i].begin(),A[i].end());
   }  
}

