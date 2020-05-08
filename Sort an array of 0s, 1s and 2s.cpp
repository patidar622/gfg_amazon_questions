#include<bits/stdc++.h>
using namespace std;
void  find_solution(vector<int>& vis)
{
    if(vis.size()==1)
    return;
    int i=0;
    while(i!=vis.size())
    {
        while(i!=vis.size() && vis[i]!=1)
        {
            i++;
        }
        if(i==vis.size())
        break;
        int j=i+1;
        while(j!= vis.size() && vis[j]!=0)
        {
            j++;
        }
        if(j==vis.size())
        break;
        if(j<vis.size() && i<vis.size())
        {
            swap(vis[i],vis[j]);
        }
        i=i+1;
    }
        i=0;
    while(i!=vis.size())
    {
        while(i!=vis.size() && vis[i]!=2)
        {
            i++;
        }
         if(i==vis.size())
        break;
        int j=i+1;
        while(j!=vis.size() && vis[j]!=0)
        {
            j++;
        }
        if(j==vis.size())
        break;
        if(j<vis.size() && i<vis.size())
        {
            swap(vis[i],vis[j]);
        }
        i=i+1;
    }
    i=0;
    while(i<vis.size())
    {
        while(i<vis.size() && vis[i]!=2)
        {
            i++;
        }
        int j=i+1;
        while(j!= vis.size() && vis[j]!=1)
        {
            j++;
        }
        if(j!=vis.size() && i!=vis.size())
        {
            swap(vis[i],vis[j]);
        }
        i=i+1;
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
	        int x;
	        cin>>x;
	        vis.push_back(x);
	    }
	    find_solution(vis);
	    for(auto i:vis)
	   { cout<<i<<" ";}
	   
	    cout<<endl;
	}
	return 0;
}
