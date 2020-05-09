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
	    long long int sum=0; 
	    long long int sum_sq=0;
	    for(int i=0;i<n;i++)
	    {
	        int x;cin>>x;
	        sum+=i+1;
	        sum-=x;
	        sum_sq+=(long long int)(i+1)*(long long int)(i+1);
	        sum_sq-=(long long int)x*(long long int)x;
	    }
	    long long int sum_ab=sum_sq/sum;
	   long long int missing=(sum_ab+sum)/2;
	    long long int repeat=sum_ab-missing;
	    cout<<repeat<<" "<<missing<<endl;
	}
	return 0;
}
