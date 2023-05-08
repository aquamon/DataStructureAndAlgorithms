// https://leetcode.com/problems/largest-perimeter-triangle/description/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        int ans = INT_MIN;
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=0; j<nums.size();j++)
        //     {
        //         for(int k=0;k<nums.size();k++)
        //         {
        //             if(i!=j and j!=k and k!=i)
        //             {
        //                 double side = (nums[i]+nums[j]+nums[k])*1.0/2;

        //                 if(side > 1.0*nums[i] and side > 1.0*nums[j] and side > 1.0*nums[k] )
        //                 {
        //                     ans = max(ans,nums[i]+nums[j]+nums[k]);
        //                 }
        //             }
        //         }
        //     }
        // }

        

        sort(nums.begin(),nums.end());

        for(int i=2;i<nums.size();i++)
        {
            double side = (nums[i-2]+nums[i-1]+nums[i])*1.0/2;
            if(side > 1.0*nums[i-2] and side > 1.0*nums[i-1] and side > 1.0*nums[i] )
            {
                ans = max(ans,nums[i-2]+nums[i-1]+nums[i]);
            }
        }

        if(ans == INT_MIN)
            return 0;
        return ans;
    }
};