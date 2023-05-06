// https://leetcode.com/problems/permutations/

class Solution {
public:

    void Solve(int i, vector<int>&nums,vector<vector<int>>&ans)
    {
        if(i == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            Solve(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>ans;

        Solve(0,nums,ans);

        return ans;
    }
};