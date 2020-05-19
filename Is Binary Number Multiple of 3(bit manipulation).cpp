#include<bits/stdc++.h>
using namespace std;
int find_solution(string s)
{
    reverse(s.begin(),s.end());
   int odd=0,even=0;
    for(int i=0;i<s.size();i++)
    {
        if(i%2==0 && s[i]=='1')
        even++;
        if(i%2!=0 && s[i]=='1')
        odd++;
    }
    if(abs(odd-even)%3==0)
    return 1;
    
    return 0;
}
int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    if(find_solution(s))
	    cout<<1<<endl;
	    else
	    cout<<0<<endl;
	}
	return 0;
}
