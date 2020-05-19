#include<bits/stdc++.h>
using namespace std;
int compare(int i1,int i2)
{
    string s1=to_string(i1);
    string s2=to_string(i2);
    if(s1+s2<s2+s1)
    return 1;
    return 0;
}
void find_solution(vector<int>& vis)
{
    for(int i=0;i<vis.size()-1;i++)
    {
        for(int j=i+1;j<vis.size();j++)
        {
            if(compare(vis[i],vis[j]))
            swap(vis[i],vis[j]);
        }
    }
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
	        int x;cin>>x;
	        vis.push_back(x);
	    }
	    find_solution(vis);
	    string ans="";
	    for(int i=0;i<vis.size();i++)
	    {
	        ans+=to_string(vis[i]);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
