#include<bits/stdc++.h>
using namespace std;
int find_solution(vector<vector<int> >&vis,int s)
{
    int i=0,j=vis[0].size()-1;
    while(1)
    {
        if(i>=vis.size() || i<0 || j<0 || j>=vis[0].size())
        return 0;
        if(vis[i][j]==s)
        return 1;
        if(vis[i][j]>s)
        j--;
        else
        i++;
    }
    return 0;
}
int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int> >vis;
	    for(int i=0;i<n;i++)
	    {
	        vector<int>v;
	        for(int j=0;j<m;j++)
	        {
	            int x;cin>>x;
	            v.push_back(x);
	        }
	        vis.push_back(v);
	        v.clear();
	    }
	    int s;
	    cin>>s;
	    cout<<find_solution(vis,s)<<endl;
	}
	return 0;
}
