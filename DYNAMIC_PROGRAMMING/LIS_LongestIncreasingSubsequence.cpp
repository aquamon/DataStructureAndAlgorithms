// https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int ans = INT_MIN;
        vector<int>LIS(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            LIS[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i])
                    LIS[i] = max(LIS[i],1+LIS[j]);
            }
            ans = max(ans,LIS[i]);
        }
        return ans;
    }
};

//TC : O(N^2) SC:O(N)