/*
In stock market , a person buys a stock and sells it on some future date.
 Given the stock prices of N days in an form of an array A[ ] and a positive integer K, 
 find out the maximum profit a person can make in atmost K transactions. 
A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.

*/
#include<bits/stdc++.h>
using namespace std;
vector<int>vis;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int k,n;
	    cin>>k>>n;
	    vis.clear();
	    for(int i=0;i<n;i++)
	    {
	        int x;
	       scanf("%d",&x);
	        vis.push_back(x);
	    }
	    if(n<=1 || k==0)
	    cout<<0<<endl;
	    else
	    {
	    int buy[n]={0};int sell[n]={0};
	    buy[0]-=vis[0];
	    for(int i=0;i<k;i++)
	    {
	        for(int j=1;j<n;j++)
	        buy[j]=max(buy[j-1],sell[j-1]-vis[j]);
	        for(int j=1;j<n;j++)
	        sell[j]=max(sell[j-1],buy[j-1]+vis[j]);
	    }
	    cout<<sell[n-1]<<endl;
	    }
	}
	return 0;
}
