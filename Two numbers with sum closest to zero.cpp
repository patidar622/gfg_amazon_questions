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
	    vector<int>vis;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        vis.push_back(x);
	    }
	    sort(vis.begin(),vis.end());
	    int i=0,j=n-1;
	    int ans=INT_MAX;
	    int ans1=0;
	    while(i<j)
	    {
	        int sum1=vis[i]+vis[j];
	        int sum=abs(vis[i]+vis[j]);
	        if(sum<ans)
	        {
	            ans=sum;
	            ans1=vis[i]+vis[j];
	        }
	        if(sum1<0)
	        i++;
	        else
	        j--;
	    }
	    cout<<ans1<<endl;
	}
	return 0;
}
