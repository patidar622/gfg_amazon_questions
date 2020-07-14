/*
Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)


*/
// the idea is that first you put all n elements in queue and when i>=1 we have to check at a 
//paritcular point where the top element is less than the sum of the two array element if we reach at that point then we find all n sums

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<int,vector<int>,greater<int>>q1;
    vector<int>ans;
    sort(A.begin(),A.end(),std::greater<int>());
    sort(B.begin(),B.end(),std::greater<int>());
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<B.size();j++)
        {
            int sum=A[i]+B[j];
            if(i==0)
            q1.push(sum);
            else if(q1.top()<sum)
            {
                q1.pop();
                q1.push(sum);
            }
            else
            break;
        }
    }
    while(!q1.empty())
    {
        ans.push_back(q1.top());
        q1.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}

