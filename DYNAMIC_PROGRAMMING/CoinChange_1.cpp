// https://leetcode.com/problems/coin-change/description/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<long long >ans(amount+1,-1);

        ans[0] = 0;

        for(int i=1;i<=amount;i++)
        {
            ans[i] = INT_MAX;
            for(int j=0;j<coins.size();j++)
            {
                if(coins[j] <= i)
                {
                    ans[i] = min(ans[i],1+ans[i-coins[j]]);
                }
            }
        }

        if(ans[amount] < INT_MAX)
            return ans[amount];
        return -1;
    }
};