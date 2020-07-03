/*
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]
*/
//time o(N^2) and o(1) space
vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int top=0,down=A.size()-1,left=0,right=A[0].size()-1;
    int dir=0;
    vector<int>ans;
    while(top<=down && left<=right)
    {
        if(dir==0)
        {
            for(int i=left;i<=right;i++)
            {
                ans.push_back(A[top][i]);
            }
            top+=1;
        }
        else if(dir==1)
        {
            for(int i=top;i<=down;i++)
            {
                ans.push_back(A[i][right]);
            }
            right-=1;
        }
        else if(dir==2)
        {
            for(int i=right;i>=left;i--)
            {
                ans.push_back(A[down][i]);
            }
            down-=1;
        }
        else if(dir==3)
        {
            for(int i=down;i>=top;i--)
            {
                ans.push_back(A[i][left]);
            }
            left+=1;
        }
        dir=(dir+1)%4;
    }
    return ans;
}

