/*
Find the largest rectangular area possible in a given histogram where the
largest rectangle can be made of a number of contiguous bars.
For simplicity, assume that all bars have same width and the width is 1 unit.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> find_left(vector<int>& vis)
{
    vector<int>left(vis.size(),0);
    stack<pair<int,int>>s1;
    for(int i=0;i<vis.size();i++)
    {
        if(s1.empty())
        {
            left[i]=-1;
        }
        else 
        {
            while(!s1.empty() && s1.top().first>=vis[i])
            {
                s1.pop();
            }
            if(s1.empty())
            left[i]=-1;
            else
            left[i]=s1.top().second;
        }
        s1.push({vis[i],i});
    }
    return left;
}
vector<int> find_right(vector<int>& vis)
{
    vector<int>right(vis.size(),0);
    stack<pair<int,int>>s1;
    for(int i=vis.size()-1;i>=0;i--)
    {
        if(s1.empty())
        {
            right[i]=vis.size();
        }
        else 
        {
            while(!s1.empty() && s1.top().first>=vis[i])
            {
                s1.pop();
            }
            if(s1.empty())
            right[i]=vis.size();
            else
            right[i]=s1.top().second;
        }
        s1.push({vis[i],i});
    }
    return right;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>vis;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        vis.push_back(x);
	    }
	    vector<int>left(n,0);
	    left=find_left(vis);
	    vector<int>right(n,0);
	    right=find_right(vis);
	   long long int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        ans=max(ans,(long long int)vis[i]*(right[i]-left[i]-1));
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
