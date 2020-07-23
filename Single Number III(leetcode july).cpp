/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/
//the basic idea is that we have two split the array into two parts such that xor of all 
//array elements and the right_bit that is on means at that positon the two no are differnt

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n1=0;
        for(int i=0;i<nums.size();i++)
        {
            n1^=nums[i];
        }
        int right_bit=n1&(-n1);
        
        vector<int>ans(2,0);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&right_bit)
                ans[0]^=nums[i];
            else
                ans[1]^=nums[i];
        }
        return ans;
    }
};
