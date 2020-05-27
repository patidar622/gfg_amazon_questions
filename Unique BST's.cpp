#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int i1=2*n,j1=n;
	    long long int num=1,deno=1;
	    while(i1>n+1 && j1>0)
	    {
	        num=num*i1;
	        deno=deno*j1;
	        int g=__gcd(num,deno);
	        if(g!=0)
	        {
	            num=num/g;
	            deno=deno/g;
	        }
	        i1--;
	        j1--;
	    }
	    while(i1>n+1)
	    {
	        num=num*i1;
	        i1--;
	    }
	    while(j1>0)
	    {
	        deno=deno*j1;
	        j1--;
	    }
	    cout<<num/deno<<endl;
	}
	return 0;
}
