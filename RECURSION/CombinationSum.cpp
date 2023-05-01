// https://leetcode.com/problems/combination-sum/

class Solution {
public:

    void allSS(vector<int>&A,int idx,int N,int remSum,vector<vector<int>>&ans,vector<int>&temp)
    {
        if(remSum == 0)
        {
            ans.push_back(temp);
            return;
        }

        if(idx >= N or remSum < 0)
        {
            return;
        }

        temp.push_back(A[idx]);
        allSS(A,idx,N,remSum-A[idx],ans,temp);
        temp.pop_back();
        
        allSS(A,idx+1,N,remSum,ans,temp);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        

        vector<vector<int>> ans;
        vector<int>temp;
        allSS(candidates,0,candidates.size(),target,ans,temp);
        return ans;
    }
};