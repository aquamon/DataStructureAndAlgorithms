// https://leetcode.com/problems/edit-distance/

//Naive : The below code will give TLE.

class Solution {
public:

    int getED(int i,int j,string &W1, string &W2)
    {
        if(i == -1) return j+1;
        if(j == -1) return i+1;

        if(W1[i] == W2[j])
            return getED(i-1,j-1,W1,W2);
        else
            return 1+min({
                getED(i-1,j-1,W1,W2),
                getED(i-1,j,W1,W2),
                getED(i,j-1,W1,W2),
            });
    }
    int minDistance(string word1, string word2) {
        
        int ans = getED(word1.length()-1,word2.length()-1,word1,word2);

        return ans;
    }
};

// Using Memoization - Top_Bottom TC : O(N^2) SC : O(N^2)

class Solution {
public:

    int getED(int i,int j,string &W1, string &W2,vector<vector<int>>&ans)
    {
        if(i == -1) return j+1;
        if(j == -1) return i+1;
        if(ans[i][j] != -1)
            return ans[i][j];
        if(W1[i] == W2[j])
            ans[i][j] = getED(i-1,j-1,W1,W2,ans);
        else
            ans[i][j] = 1+min({
                getED(i-1,j-1,W1,W2,ans),
                getED(i-1,j,W1,W2,ans),
                getED(i,j-1,W1,W2,ans)
            });
        
        return ans[i][j];
    }
    int minDistance(string word1, string word2) {
        
        vector<vector<int>>ans(word1.length(),vector<int>(word2.length(),-1));
        int answer = getED(word1.length()-1,word2.length()-1,word1,word2,ans);

        return answer;
    }
};

// Bottom UP TC : O(N^2) SC : O(N^2)
class Solution {
public:

    int getED(string &W1, string &W2,vector<vector<int>>&ans)
    {
        for(int j=0;j<=W2.length();j++)
        {
            ans[0][j] = j;
        }
        for(int i=0;i<=W1.length();i++)
        {
            ans[i][0] = i;
        }
        
        for(int i=1;i<=W1.length();i++)
        {
            for(int j=1;j<=W2.length();j++)
            {
                if(W1[i-1] == W2[j-1])
                    ans[i][j] = ans[i-1][j-1];
                else
                {
                    ans[i][j] = 1 + min({ans[i-1][j-1] , ans[i-1][j] , ans[i][j-1]});
                }
            }
        }
        return ans[W1.length()][W2.length()];
    }
    int minDistance(string word1, string word2) {
        
        vector<vector<int>>ans(word1.length()+1,vector<int>(word2.length()+1,-1));
        int answer = getED(word1,word2,ans);

        return answer;
    }
};

// Space Optimization SC : O(N)

class Solution {
public:

    int getED(string &W1, string &W2,vector<int>&ans)
    {
        for(int j=0;j<=W2.length();j++)
        {
            ans[j] = j;
        }
        vector<int>temp(W2.length()+1);
        for(int i=1;i<=W1.length();i++)
        {
            temp[0] = i;
            for(int j=1;j<=W2.length();j++)
            {
                if(W1[i-1] == W2[j-1])
                    temp[j] = ans[j-1];
                else
                {
                    temp[j] = 1 + min({ans[j-1] , ans[j] , temp[j-1]});
                }
            }
            ans = temp;
        }
        return ans[W2.length()];
    }
    int minDistance(string word1, string word2) {
        
        vector<int>ans(word2.length()+1,-1);
        int answer = getED(word1,word2,ans);

        return answer;
    }
};