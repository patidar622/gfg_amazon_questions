#include<bits/stdc++.h>
using namespace std;
int find_solution(vector<int>& vis,int i,int j,int target)
{
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(vis[mid]==target)
        return mid;
        if(vis[mid]>=vis[i])
        {
            if(vis[mid]>=target && target>=vis[i])
            j=mid-1;
            else
            i=mid+1;
        }
        else if(mid+1!=vis.size() && vis[mid+1]<=vis[j])
        {
            if(vis[mid+1]<=target && target<=vis[j])
            i=mid+1;
            else
            j=mid-1;
        }
    }
    return -1;
}
int main()
 {
	//code
	int t;scanf("%d",&t);
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>vis;
	    for(int i=0;i<n;i++)
	    {
	        int x;scanf("%d",&x);
	        vis.push_back(x);
	    }
	    int target;
	    scanf("%d",&target);
	    cout<<find_solution(vis,0,n-1,target)<<endl;
	    /*
	    int i=0,j=n-1,ans=-1;
	     while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(vis[mid]==target)
        {ans=mid;
        break;}
        if(vis[mid]>target && vis[mid]>=vis[i] && target<vis[i])
            i=mid+1;
        else if(vis[mid]<target &&vis[mid]<=vis[j] && target>vis[j])
        j=mid-1;
        else if(vis[mid]<target)
            i=mid+1;
            else
            j=mid-1;
    }
	    printf("%d\n",ans);*/
	}
	return 0;
}
