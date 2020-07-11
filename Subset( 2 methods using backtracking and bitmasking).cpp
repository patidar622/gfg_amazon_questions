/*
Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
*/
vector<vector<int> >ans;

void find_solution(vector<int> &A,vector<int> v1,int i)
{
    if(i==A.size())
    {
        sort(v1.begin(),v1.end());
        ans.push_back(v1);
        return;
    }
    v1.push_back(A[i]);
    find_solution(A,v1,i+1);
    v1.pop_back();
    find_solution(A,v1,i+1);
    return;
}
vector<vector<int> > Solution::subsets(vector<int> &A) {

ans.clear();
vector<int>v1;
find_solution(A,v1,0);
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    return ans;
    
    //another solution better approach using bit manipulation
   
   /* ans.clear();
    sort(A.begin(),A.end());
    for(int i=0;i<(1<<A.size());i++)
    {
        vector<int>v1;
        for(int j=0;j<A.size();j++)
        {
            if(i & (1<<j))
            v1.push_back(A[j]);
        }
        ans.push_back(v1);
        v1.clear();
    }
    sort(ans.begin(),ans.end());
    return ans;
    /*
}

