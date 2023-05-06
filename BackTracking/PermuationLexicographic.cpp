// https://leetcode.com/problems/permutation-sequence/description/

class Solution {
public:

    string res = "";
    void RightRotate(int i,int j,vector<int>&nums)
    {
        int X = nums[j];

        for(int k=j;k>i;k--)
        {
            nums[k] = nums[k-1];
        }
        nums[i] = X;
    }

    void LeftRotate(int i, int j, vector<int>&nums)
    {
        int X = nums[i];

        for(int k=i+1;k<=j;k++)
        {
            nums[k-1] = nums[k];
        }
        nums[j] = X;
    }
    void permute(int i,vector<int>& nums,int &k,bool &ans_found)
    {
        if(i == nums.size()-1)
        {
            if(k == 1)
            {
                for(int i=0;i<nums.size();i++)
                {
                    res.push_back(nums[i] + '0');
                }
                ans_found = true;
                return;
            }
            k--;
            return;
        }

        for(int j=i;j<nums.size();j++)
        {
            RightRotate(i,j,nums);
             if(!ans_found)
                permute(i+1,nums,k,ans_found);
            LeftRotate(i,j,nums);
        }
    }
    string getPermutation(int n, int k) {
        
        vector<int>nums(n,0);
        for(int i=0;i<n;i++)
            nums[i] = i+1;
        
        bool ans_found = false;
        permute(0,nums,k,ans_found);
        return res;
    }
};