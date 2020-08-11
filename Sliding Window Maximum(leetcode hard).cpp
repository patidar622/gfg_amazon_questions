/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length



*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q1;
        for(int i=0;i<k;i++)
        {
            while(!q1.empty() && nums[i]>=nums[q1.back()])
            {
                q1.pop_back();
            }
            q1.push_back(i);
        }
        vector<int>ans;
        int p=0;
        for(int i=k;i<nums.size();i++)
        {
            ans.push_back(nums[q1.front()]);
            while(!q1.empty() && nums[i]>=nums[q1.back()])
            {
                q1.pop_back();
            }
            while(!q1.empty() && i-k>=q1.front())
            {
                q1.pop_front();
            }
            q1.push_back(i);
        }
        ans.push_back(nums[q1.front()]);
        return ans;
    }
};
