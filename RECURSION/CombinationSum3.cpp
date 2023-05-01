// https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:

    void comSum(vector<vector<int>>&ans,vector<int>&temp,int S,int K,int num)
    {
        if(temp.size() == K)
        {
            if(S == 0)
                ans.push_back(temp);
            return;
        }
        // if(temp.size() > K or S < 0)
        //     return;
        
        if(num > 9)
            return;
        temp.push_back(num);
        comSum(ans,temp,S-num,K,num+1);
        temp.pop_back();
        comSum(ans,temp,S,K,num+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        vector<int>temp;

        comSum(ans,temp,n,k,1);

        return ans;

    }
};