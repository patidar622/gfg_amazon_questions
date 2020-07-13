/*
Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)
If no solution is possible, return an empty list.

using hashing o(n2) solution 

*/
vector<int> Solution::equal(vector<int> &A) {
    map<int,vector<pair<int,int> > >m1;
    vector<int>ans(4,INT_MAX);
    
    for(int i=0;i<A.size()-1;i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            int sum=A[i]+A[j];
            m1[sum].push_back({i,j});
        }
    }
    
    for(auto i:m1)
    {
        if(i.second.size()>=2)
        {
            for(int i1=0;i1<i.second.size();i1++)
            {
                pair<int,int>p1=i.second[0];
                pair<int,int>p2=i.second[i1];
                
                if(p1.first<p2.first && p1.second!=p2.first && p1.second!=p2.second)
                {
                    vector<int>v1;
                    v1.push_back(p1.first);v1.push_back(p1.second);v1.push_back(p2.first);v1.push_back(p2.second);
                    if(v1<ans)
                    ans=v1;
                }
            }
        }
    }
    
    return ans;
    
}

