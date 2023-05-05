// https://leetcode.com/problems/unique-paths/description/

// Recursive : 

class Solution {
public:

    int countPaths(int i,int j)
    {
        if(i==0 or j==0)
            return 1;
        
        return countPaths(i-1,j) + countPaths(i,j-1);
    }
    int uniquePaths(int m, int n) {
        
        return countPaths(m-1,n-1);
    }
};

// Memoized

class Solution {
public:

    int countPaths(int i,int j,vector<vector<int>>&ans)
    {
        if(i==0 or j==0)
            return 1;
        if(ans[i][j] != -1)
            return ans[i][j];
        
        ans[i][j] =  countPaths(i-1,j,ans) + countPaths(i,j-1,ans);

        return ans[i][j];
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>ans(m,vector<int>(n,-1));
        return countPaths(m-1,n-1,ans);
    }
};

// Bottop - Top

class Solution {
public:

    int countPaths(int i,int j,vector<vector<int>>&ans)
    {
        for(int i=0;i<ans.size();i++)
            ans[i][0] = 1;
        for(int j=0;j<ans[0].size();j++)
            ans[0][j] = 1;
        
        for(int i=1;i<ans.size();i++)
        {
            for(int j=1;j<ans[0].size();j++)
            {
                ans[i][j] = ans[i-1][j] + ans[i][j-1];
            }
        }

        return ans[ans.size()-1][ans[0].size()-1];
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>ans(m,vector<int>(n,-1));
        return countPaths(m-1,n-1,ans);
    }
};

// Space Optimized

class Solution {
public:

    int countPaths(int m,int n,vector<int>&ans)
    {
      
        vector<int>temp(n,0);
        for(int i=1;i<m;i++)
        {
            temp[0] = 1;
            for(int j=1;j<n;j++)
            {
                temp[j] = temp[j-1] + ans[j];
            }
            ans = temp;
        }

        return ans[n-1];
    }
    int uniquePaths(int m, int n) {
        
        vector<int>ans(n,1);
        return countPaths(m,n,ans);
    }
};