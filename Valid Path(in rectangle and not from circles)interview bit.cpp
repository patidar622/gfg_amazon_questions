/*
There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle.
Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.
Input Format
1st argument given is an Integer x.
2nd argument given is an Integer y.
3rd argument given is an Integer N, number of circles.
4th argument given is an Integer R, radius of each circle.
5th argument given is an Array A of size N, where A[i] = x cordinate of ith circle
6th argument given is an Array B of size N, where B[i] = y cordinate of ith circle
Output Format

Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).
Constraints

0 <= x, y, R <= 100
1 <= N <= 1000
Center of each circle would lie within the grid
For Example

Input:
    x = 2
    y = 3
    N = 1
    R = 1
    A = [2]
    B = [3]
Output:
    NO
   
Explanation:
    There is NO valid path in this case

*/
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    
    map<pair<int,int>,int>s1;
   map<pair<int,int>,int>s2;
   for(int i=0;i<=A;i++)
   {
       for(int j=0;j<=B;j++)
      {
          for(int k=0;k<C;k++){
          double d1=sqrt(pow(E[k]-i,2)+pow(F[k]-j,2));
          if(d1<=(double)D)
          {
              s1[{i,j}]=1;
          }
          }
      }
   }
    int dis[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    queue<pair<int,int>>q1;
    if(s1.find({0,0})!=s1.end() || s1.find({A,B})!=s1.end())
    return "NO";
    q1.push({0,0});
    s2[{0,0}]=1;
    while(!q1.empty())
    {
        pair<int,int>p1=q1.front();q1.pop();
        if(p1.first==A && p1.second==B)
        return "YES";
        for(int i=0;i<8;i++)
        {
            int new_r=p1.first+dis[i][0],new_c=p1.second+dis[i][1];
            if(new_r>=0 && new_r<=A && new_c>=0 && new_c<=B && s1.find({new_r,new_c})==s1.end() && s2.find({new_r,new_c})==s2.end())
            {
                s2[{new_r,new_c}]=1;
                q1.push({new_r,new_c});
            }
        }
    }
    return "NO";
}

