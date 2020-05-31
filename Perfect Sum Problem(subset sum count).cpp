#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
long long int m=1000000007;
int find_solution(vector<int>& vis,int n,int sum)
 {
     if(sum==0)
     return 1;
     if(n<0)
     return 0;
     
     if(dp[n][sum]!=-1)
     return dp[n][sum];
     
     if(vis[n]<=sum)
     return dp[n][sum]=(find_solution(vis,n-1,sum-vis[n])+find_solution(vis,n-1,sum))%m;
     else
     return dp[n][sum]=find_solution(vis,n-1,sum)%m;
 }
int main()
 {
	int t;cin>>t;
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
	    int sum;
	    cin>>sum;
	   dp.resize(n+1,vector<int>(sum+1,0));
	 //  cout<<find_solution(vis,n-1,sum)%m<<endl;
	   for(int i=0;i<=n;i++)
	   {
	       for(int j=0;j<=sum;j++)
	       {
	           if(j==0)
	           dp[i][j]=1;
	           else if(i==0 && j!=0)
	           dp[i][j]=0;
	           else if(vis[i-1]<=j)
	           dp[i][j]=(dp[i-1][j-vis[i-1]]+dp[i-1][j])%m;
	           else
	           dp[i][j]=dp[i-1][j]%m;
	       }
	   }
	  cout<<dp[n][sum]%m<<endl;
	  dp.clear();
	}
	return 0;
}
