//ye logic easy he understanding ke liye just find NSL(nearest smallest left) and NSR(nearest smallest right) and subtract to find the width and multiply that with given height
//so we can use this to find the largest ractangle in histogram


vector<int> find_left(vector<int>& vis)
{
    stack<int>s1;
    vector<int>left(vis.size(),0);
    for(int i=0;i<vis.size();i++)
    {
        if(s1.empty())
        left[i]=-1;
        else if(vis[s1.top()]<vis[i])
        left[i]=s1.top();
        else
        {
            while(!s1.empty() && vis[s1.top()]>=vis[i])
            {
                s1.pop();
            }
            if(s1.empty())
            left[i]=-1;
            else
            left[i]=s1.top();
        }
        s1.push(i);
    }
    return left;
}
vector<int> find_right(vector<int>& vis)
{
    stack<int>s1;
    vector<int>right(vis.size(),0);
    for(int i=vis.size()-1;i>=0;i--)
    {
        if(s1.empty())
       right[i]=vis.size();
        else if(vis[s1.top()]<vis[i])
        right[i]=s1.top();
        else
        {
            while(!s1.empty() && vis[s1.top()]>=vis[i])
            {
                s1.pop();
            }
            if(s1.empty())
            right[i]=vis.size();
            else
            right[i]=s1.top();
        }
        s1.push(i);
    }
    return right;
}
int find_solution(vector<int>&vis)
{
    vector<int>left(vis.size(),0);
    vector<int>right(vis.size(),0);
    left=find_left(vis);
    right=find_right(vis);
    int ans=0;
    for(int i=0;i<vis.size();i++)
    {
        ans=max(ans,vis[i]*(right[i]-left[i]-1));
    }
    return ans;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
   vector<int>vis(m,0);
   int ans=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(A[i][j]==0)
           vis[j]=0;
           else
           vis[j]+=1;
          
       }
        ans=max(ans,find_solution(vis));
   }
   return ans;
}

/*//ye samjh nahi aaya he

Given a binary matrix, 
Your task is to complete the function maxArea which the maximum size rectangle area in
 a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and 
 the next two are two  integers n and m which denotes the size of the matrix M.
  Your function should return an integer denoting the area of the maximum rectangle .

int find_maxRectangle(vector<int>& vis)
{
    int ans=0,max_area=0;
    stack<int>s1;
    int i=0;
    while(i<vis.size())
    {
        if(s1.empty() || vis[s1.top()]<=vis[i])
        s1.push(i++);
        else
        {
            int top_val=vis[s1.top()];
            s1.pop();
            if(s1.empty())
            ans=top_val*i;
            else
            ans=top_val*(i-s1.top()-1);
            max_area=max(ans,max_area); 
        }
    }
    while(!s1.empty())
    {
        int top_val=vis[s1.top()];
        s1.pop();
        if(s1.empty())
        ans=top_val*i;
        else
        ans=top_val*(i-s1.top()-1);
        max_area=max(ans,max_area);
    }
    return max_area;
}

int maxArea(int M[MAX][MAX], int n, int m) {
    vector<int>vis(m,0);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j]==0)
            vis[j]=0;
            else
            vis[j]+=M[i][j];
        }
        ans=max(ans,find_maxRectangle(vis));
    }
    return ans;
}
*/
