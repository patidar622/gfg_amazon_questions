/*
Problem Description

It’s Tushar’s birthday today and he has N friends.

Friends are numbered [0, 1, 2, ...., N-1] and ith friend have a positive strength B[i].

Today being his birthday, his friends have planned to give him birthday bombs (kicks).

Tushar's friends know Tushar's pain bearing limit and would hit accordingly.

If Tushar’s resistance is denoted by A (>=0) then find the lexicographically smallest order of friends to kick Tushar so that the cumulative kick strength (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no. of kicks hit are maximum.

Also note that each friend can kick unlimited number of times (If a friend hits x times, his strength will be counted x times)

Return the lexicographically smallest array of maximum length where the ith index represents the index of the friend who will hit.

NOTE:

[a1, a2, ...., am] is lexicographically smaller than [b1, b2, .., bm] if a1 < b1 or (a1 = b1 and a2 < b2) ... .
Input cases are such that the length of the answer does not exceed 100000.


Problem Constraints
1 <= N <= 100

1 <= A <= 15 * 106

1 <= B[i] <= 105



Input Format
The first argument contains an integer, A of length N.

The second argument contains an array of integers B.



Output Format
Return an array of integer, as described in the problem statement.



Example Input
Input 1:

 A = 12
 B = [3, 4]
Input 2:

 A = 11
 B = [6, 8, 5, 4, 7]


Example Output
Output 1:

 [0, 0, 0, 0]
Output 2:

 [0, 2]





*/
/*
vector<int>ans;
vector<pair<int,int>>vis;
int m1;
void find_solution(int A,vector<int>& v1)
{
    if(A<m1)
    {
        if(v1.size()>ans.size() || v1.size()==ans.size() && v1<ans)
        {
            ans=v1;
            return;
        }
    }
    int i=0;
    while(i<vis.size() && vis[i].first<=A)
    {
            v1.push_back(vis[i].second);
            find_solution(A-vis[i].first,v1);
            v1.pop_back();
            i++;
    }
    return;
}
bool comparator(const pair<int,int>v1,const pair<int,int>v2)
{
    return v1.first<v2.first || v1.first==v2.first && v1.second<=v2.second;
}*/
vector<int> Solution::solve(int A, vector<int> &B) {
    int i1=min_element(B.begin(),B.end())-B.begin();
    int max_kicks=A/B[i1];
    int curr_max=max_kicks*B[i1];
    vector<int>ans(max_kicks,i1);
    
    int i=0,c=0;
    while(c<max_kicks && i<i1)
    {
        int temp=curr_max-B[ans[c]]+B[i];
        if(temp>curr_max && temp<=A)
        {
            ans[c++]=i;
            curr_max=temp;
        }
        else
        i++;
    }
    return ans;
    
   /* 
   //these solution is giving tle because we have to take greedy approach 
   ans.clear();
   vis.clear();
   m1=INT_MAX;
    for(int i=0;i<B.size();i++)
    {
        m1=min(m1,B[i]);
        vis.push_back({B[i],i});
    }
    sort(vis.begin(),vis.end(),comparator);
    vector<int>v1;
    find_solution(A,v1);
    return ans;*/
}

