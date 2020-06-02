#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>vis;
bool find_row(int row,int i1)
{
    for(int i=0;i<9;i++)
    {
        if(vis[row][i]==i1)
        return false;
    }
    return true;
}
bool find_col(int col,int i1)
{
    for(int i=0;i<9;i++)
    {
        if(vis[i][col]==i1)
        return false;
    }
    return true;
}
bool find_mat(int row,int col,int i1)
{
    int start_row=row-row%3;
    int start_col=col-col%3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(vis[start_row+i][start_col+j]==i1)
            return false;
        }
    }
    return  true;
}
bool find_safe(vector<pair<int,int>>& v1,int i,int i1)
{
    if(find_row(v1[i].first,i1) && find_col(v1[i].second,i1) && find_mat(v1[i].first,v1[i].second,i1))
    return true;
    
    return false;
}
int find_solution(vector<pair<int,int>>& v1,int i)
{
    if(i==v1.size())
    return 1;
    
    
    for(int i1=1;i1<=9;i1++)
    {
        if(find_safe(v1,i,i1))
        {
            vis[v1[i].first][v1[i].second]=i1;
            if(find_solution(v1,i+1))
            return 1;
            
            vis[v1[i].first][v1[i].second]=0;
        }
    }
    return 0;
    
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    vis.resize(9,vector<int>(9,0));
	    vector<pair<int,int>>v1;
	    for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	        {
	            int x;
	            cin>>x;
	            if(x==0)
	            {
	                v1.push_back({i,j});
	            }
	            vis[i][j]=x;
	        }
	    }
	    if(find_solution(v1,0))
	    cout<<1<<endl;
	    else
	    cout<<0<<endl;
	}
	return 0;
}
