#include<bits/stdc++.h>
using namespace std;
int find_solution(vector<int>& vis,int i,int j)
{ 
    int mid=i+(j-i)/2;
    while(i<j)
    {
         if(vis[mid]<vis[j])
         return find_solution(vis,i,mid);
         else 
         return find_solution(vis,mid+1,j);
    }
    return vis[i];
}
int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    vector<int>vis;
	    for(int i=0;i<n;i++)
	    {
	        int x;cin>>x;
	        vis.push_back(x);
	    }
	    cout<<find_solution(vis,0,vis.size()-1)<<endl;
	}
	return 0;
}
