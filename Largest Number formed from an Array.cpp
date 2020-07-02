/*
/*
This “comparator” function returns a value; convertible to bool,
which basically tells us whether the passed “first” argument should be 
placed before the passed “second” argument or not.
*/
// ye wala interview bit ka he

bool comparator(string s1,string s2)
{
    if(s1+s2>=s2+s1)
    return 1;
    return 0;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<string>vis;
    for(int i=0;i<A.size();i++)
    {
        vis.push_back(to_string(A[i]));
    }
    sort(vis.begin(),vis.end(),comparator);
    string ans="";
    for(int i=0;i<vis.size();i++)
    {
        ans+=vis[i];
    }
    while(ans[0]=='0' && ans.size()>1)
    {
        ans.erase(ans.begin()+0);
    }
    return ans;
}
*/
// geeks ka he
	
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
