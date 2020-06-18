/*
Given a collection of Intervals,merge all the overlapping Intervals.
For example:

Given [1,3], [2,6], [8,10], [15,18],

return [1,6], [8,10], [15,18].

Make sure the returned intervals are sorted.

*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<pair<int,int>>vis;
	    for(int i=0;i<n;i++)
	    {
	        int x,y;
	        cin>>x>>y;
	        vis.push_back({x,y});
	    }
	    sort(vis.begin(),vis.end());
	    vector<pair<int,int>>ans;
	    ans.push_back(vis[0]);
	    for(int i=1;i<n;i++)
	    {
	        if(ans.back().second>=vis[i].first)
	        ans.back().second=max(ans.back().second,vis[i].second);
	        else
	        ans.push_back(vis[i]);
	    }
	    for(auto i:ans)
	    {
	        cout<<i.first<<" "<<i.second<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
