/*
Given N activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Note : The start time and end time of two activities may coincide.
*/
#include<bits/stdc++.h>
using namespace std;
bool comparator(pair<int,int>p1,pair<int,int>p2)
{
    return p1.first<p2.first || (p1.first==p2.first && p1.second<=p2.second);
}
vector<int>dp;
int find_solution(vector<pair<int,int> >& vis,int i)
{
    if(i==vis.size())
    return 0;
    if(i==vis.size()-1)
    return 1;
    if(dp[i]!=-1)
    return dp[i];
    int ans=0;
    for(int i1=i+1;i1<vis.size();i1++)
    {
        if(vis[i].second<=vis[i1].first)
        ans=max(ans,max(find_solution(vis,i1),find_solution(vis,i1+1)));
    }
    return dp[i]=ans+1;
}
int main()
 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
	int t;cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>v1,v2;
	    for(int i=0;i<n;i++)
	    {
	        int x;cin>>x;
	        v1.push_back(x);
	    }
	    for(int i=0;i<n;i++)
	    {
	        int x;cin>>x;v2.push_back(x);
	    }
	    vector<pair<int,int> >vis;
	    for(int i=0;i<n;i++)
	    {
	        vis.push_back({v1[i],v2[i]});
	    }
	    sort(vis.begin(),vis.end(),comparator);
	    dp.resize(n+1,-1);
	    for(int i=0;i<n;i++){
	   find_solution(vis,i);
	    }
	   
	   cout<<*max_element(dp.begin(),dp.end())<<endl;
	    dp.clear();
	}
	return 0;
}
