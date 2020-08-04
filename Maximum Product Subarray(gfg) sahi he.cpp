#include<bits/stdc++.h>
using namespace std;
long long int max1(long long int i1,long long int i2)
{
    return i1>=i2?i1:i2;
}
long long int min1(long long int i1,long long int i2)
{
    return i1<=i2?i1:i2;
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
	    vector<int>vis;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        vis.push_back(x);
	    }
	    long long int ans=vis[0],curr_max_prod=vis[0],curr_min_prod=vis[0],prev_max_prod=vis[0],prev_min_prod=vis[0];
	   
	    for(int i=1;i<n;i++)
	    {
	        curr_max_prod=max1(max1(prev_max_prod*vis[i]%1000000007,prev_min_prod*vis[i]%1000000007),vis[i]%1000000007)%1000000007;
	        curr_min_prod=min1(min1(prev_max_prod*vis[i]%1000000007,prev_min_prod*vis[i]%1000000007),vis[i]%1000000007)%1000000007;
	        ans=max1(ans%1000000007,curr_max_prod%1000000007)%1000000007;
	        prev_max_prod=curr_max_prod%1000000007;
	        prev_min_prod=curr_min_prod%1000000007;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
