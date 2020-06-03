/*
Given a number K and string S of digits denoting a positive integer, 
build the largest number possible by performing swap operations on the digits of S atmost K times.

*/
#include<bits/stdc++.h>
using namespace std;
string ans;
string max1(string s1,string s2)
{
    int i=0;
    while(i<s1.size())
    {
        if(s1[i]<s2[i])
        return s2;
        else if(s1[i]>s2[i])
        return s1;
        
        i++;
    }
    return s1;
}
void find_solution(string s,int i1,int k)
{
    
    if(k==0 || i1==s.size())
    return;
    
    for(int i=i1;i<s.size()-1;i++){
    for(int j=i+1;j<s.size();j++)
    {
        if(s[i]<s[j])
        {
            swap(s[i],s[j]);
            ans=max1(ans,s);
            find_solution(s,i1+1,k-1);
            swap(s[i],s[j]);
        }
    }
    }
    return;
}
int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int k;cin>>k;
	    string s;
	    cin>>s;
	    ans=s;
	    find_solution(s,0,k);
	    cout<<ans<<endl;
	}
	return 0;
}
