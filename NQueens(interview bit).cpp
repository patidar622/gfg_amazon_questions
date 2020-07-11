/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]



*/
vector<vector<string> >ans;
vector<string>v1;
bool find_col(int A,int j)
{
    for(int i=0;i<A;i++)
    {
        if(v1[i][j]=='Q')
        return false;
    }
    return true;
}
bool find_diagonal(int A,int i,int j)
{
    int i1=i,j1=j,i2=i,j2=j;
    while(i1>=0 && j1>=0)
    {
        if(v1[i1][j1]=='Q')
        return false;
        i1--;j1--;
    }
    while(i2>=0 && j2<A)
    {
        if(v1[i2][j2]=='Q')
        return false;
        i2--;j2++;
    }
    return true;
}
bool find_valid(int A,int i,int j)
{
    return find_col(A,j) && find_diagonal(A,i,j);
}
void find_solution(int A,int i)
{
    if(i==A)
    {
        ans.push_back(v1);
        return;
    }
    
    for(int j=0;j<A;j++)
    {
        if(find_valid(A,i,j))
        {
            v1[i][j]='Q';
            find_solution(A,i+1);
            v1[i][j]='.';
        }
    }
    return;
    
}
vector<vector<string> > Solution::solveNQueens(int A) {
    ans.clear();
    string s="";
    v1.clear();
    for(int i=0;i<A;i++)
    {
        s.push_back('.');
    }
    for(int i=0;i<A;i++)
    {
        v1.push_back(s);
    }
    find_solution(A,0);
    return ans;
}

