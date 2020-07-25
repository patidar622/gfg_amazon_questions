/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0�s) or contain magic orbs that increase the knight�s health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight�s minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path

RIGHT-> RIGHT -> DOWN -> DOWN.

Dungeon Princess: Example 1



Input arguments to function:
Your function will get an M*N matrix (2-D array) as input which represents the 2D grid as described in the question. Your function should return an integer corresponding to the knight�s minimum initial health required.



 Note:
The knight�s health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.


*/
// logic == kabhi hame kisi cell se uske adjcents cell tak pahuch gaye toh cell[i][j]=0 or kabhi nahi ja sakte toh cell[i][j]=cell[i][j]+max(cell[i+1][j],cell[i][j+1]);;
  
int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 && j==m-1)
            A[i][j]=min(0,A[i][j]);
            else if(i==n-1)
            A[i][j]=min(0,A[i][j]+A[i][j+1]);
            else if(j==m-1)
            A[i][j]=min(0,A[i][j]+A[i+1][j]);
            else
            A[i][j]=min(0,A[i][j]+max(A[i+1][j],A[i][j+1]));
        }
    }
    return abs(A[0][0])+1;
}

