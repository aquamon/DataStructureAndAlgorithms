// https://leetcode.com/problems/advantage-shuffle/description/

// Brute Force : TLE

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>ans(nums1.size(),0);

        for(int i=0;i<nums1.size();i++)
        {
            
            int n2 = nums2[i];

            int swap_val = INT_MAX;
            int swap_idx = -1;
            for(int j=0;j<nums1.size();j++)
            {
                if(nums1[j] != -1 and nums1[j] > n2)
                {
                    if(nums1[j] < swap_val)
                    {
                        swap_val = nums1[j];
                        swap_idx = j;
                    }

                }
            }


            if(swap_idx != -1)
            {
                ans[i] = swap_val;
                nums1[swap_idx] = -1;
            }
            
        }

        vector<int>left_over;

        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i] != -1)
                left_over.push_back(nums1[i]);
        }

        for(int i=0;i<ans.size();i++)
        {
            if(ans[i] == 0)
            {
                ans[i] = left_over[left_over.size()-1];
                left_over.pop_back();
            }
        }

        return ans;
    }
};

// Efficient

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        
        multiset<int>S;

        for(int i=0;i<nums1.size();i++)
        {
            S.insert(nums1[i]);
        }

        vector<int>ans;

        for(int i=0;i<nums1.size();i++)
        {
            auto it = S.upper_bound(nums2[i]);

            if(it == S.end())
            {
                
                ans.push_back(*S.begin());
                S.erase(S.begin());
            }
            else
            {
                ans.push_back(*it);
                S.erase(it);
            }
        }

        return ans;


    }
};