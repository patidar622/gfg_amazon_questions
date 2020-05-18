#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int  t;cin>>t;
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
	    unordered_map<int,int>m1;
	    m1[0]=1;
	    int count=0,sum=0;
	    for(int i=0;i<n;i++)
	    {
	         sum+=vis[i];
	        if(m1.find(sum)!=m1.end())
	        {
	            count+=m1[sum];
	        }
	        m1[sum]++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}
