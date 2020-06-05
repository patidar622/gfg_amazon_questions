/*
Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
*/
class Solution {
public:
    vector<int>vis;
    int sum;
    Solution(vector<int>& w) {
        sum=0;
        for(int i=0;i<w.size();i++)
        {
            sum+=w[i];
            vis.push_back(sum);
        }
    }
    int find_solution(int p)
    {
        int i=0,j=vis.size()-1;
        int ans=0;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(vis[mid]>=p)
            {
                ans=mid;
                j=mid-1;
            }
            else
                i=mid+1;
        }
        return ans;
    }
    
    int pickIndex() {
        int p=rand()%sum;
        return find_solution(p+1);     
    }
};
