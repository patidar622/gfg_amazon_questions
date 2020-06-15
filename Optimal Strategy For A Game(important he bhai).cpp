/*
You are given an array A of size N.
 The array contains integers and is of even length.
  The elements of the array represent N coin of values V1, V2, ....Vn. 
  You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, 
removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amouint of money you can win if you go first.

*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
int find_solution(vector<int>& vis,int i,int j)
{
    if(i==j)
    return vis[i];
    if(i+1==j)
    return max(vis[i],vis[j]);
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    return dp[i][j]=max(vis[i]+min(find_solution(vis,i+2,j),
    find_solution(vis,i+1,j-1)),
    vis[j]+min(find_solution(vis,i+1,j-1),
    find_solution(vis,i,j-2)));
   
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
	    dp.resize(n,vector<int>(n,-1));
	     cout<<find_solution(vis,0,n-1)<<endl;
	     dp.clear();
	}
	return 0;
}
