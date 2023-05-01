// https://leetcode.com/problems/combinations/

class Solution {
public:

    void comSum(vector<int>&temp,vector<vector<int>>&ans,int K, int num,int N)
    {
        if(temp.size() == K)
        {
            ans.push_back(temp);
            return;
        }
        if(temp.size() > K or num > N)
        {
            return;
        }
        
        temp.push_back(num);
        comSum(temp,ans,K,num+1,N);
        temp.pop_back();
        comSum(temp,ans,K,num+1,N);
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>temp;
        vector<vector<int>>ans;

        comSum(temp,ans,k,1,n);
        return ans;
        
    }
};