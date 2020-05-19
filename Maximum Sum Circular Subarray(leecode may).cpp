class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int ans=0,c=0;
        int sum1=0;int sum=0;int negative_max=INT_MIN;
        int max_sum=INT_MIN;
        int k_sum=0,k_ans=INT_MIN;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>0)
                c=1;
            else
                negative_max=max(negative_max,A[i]);
            k_sum+=A[i];
            if(k_sum<0)
                k_sum=0;
            if(k_sum>k_ans)
                k_ans=k_sum;
         
            A[i]= -1*A[i];
               sum+=A[i];
              sum1+=A[i];
             if(sum1<0)
                sum1=0;
            if(sum1>max_sum)
                max_sum=sum1;
           
        }
        if(c==0)
            return negative_max;
        ans=-1*(sum-max_sum);
        return max(ans,k_ans);
    }
};
