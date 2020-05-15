#include<bits/stdc++.h>
using namespace std;
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
	    vector<int>ans(n,1);
	    stack<int>s;
	    for(int i=0;i<n;i++)
	    {
	        if(s.empty())
	        {
	            s.push(i);
	        }
	        else if(vis[s.top()]<=vis[i])
	        {
	            while(!s.empty() && vis[s.top()]<=vis[i])
	            {
	                ans[i]=ans[i]+ans[s.top()];
	                s.pop();
	            }
	            s.push(i);
	        }
	        else
	        s.push(i);
	    }
	    for(auto i:ans)
	    {
	        cout<<i<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
