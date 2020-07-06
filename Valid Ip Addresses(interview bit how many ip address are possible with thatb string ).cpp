/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. 
The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)


*/
vector<string>ans;
bool find_valid(vector<string>vis)
{
    for(int i=0;i<vis.size();i++)
    {
        if(vis[i].size()>3)
        return false;
        long long int i1=stoi(vis[i]);
        if(i1>255 || i1<0)
        return false;
        if(vis[i].size()>1 && vis[i][0]=='0')
        return false;
        for(int i1=0;i1<vis[i].size();i1++)
        {
            if(!isdigit(vis[i][i1]))
            return false;
        }
        
    }
    return true;
}
void find_sol(vector<string>vis)
{
    string s1="";
    for(int i=0;i<vis.size();i++)
    {
        s1=s1+vis[i];
        if(i!=vis.size()-1)
        s1.push_back('.');
    }
    ans.push_back(s1);
}
void find_solution(string A,int i,vector<string>vis,int count)
{
    if(i>=A.size())
    return;
    if(count==3)
    {
        string s1=A.substr(i,A.size()-i);
        vis.push_back(s1);
        if(find_valid(vis))
        find_sol(vis);
        vis.pop_back();
        return;
    }
    if(count>3)
    return;
    
    for(int i1=i;i1<=i+2;i1++)
    {
        string s=A.substr(i,i1-i+1);
        vis.push_back(s);
        find_solution(A,i1+1,vis,count+1);
        vis.pop_back();
    }
    return;
}
vector<string> Solution::restoreIpAddresses(string A) {
    ans.clear();
    vector<string>vis;
    find_solution(A,0,vis,0);
    return ans;
}

