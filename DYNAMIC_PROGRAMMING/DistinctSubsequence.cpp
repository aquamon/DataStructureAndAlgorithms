// https://leetcode.com/problems/distinct-subsequences/description/

class Solution {
public:

    int countSS(int i,string&s,int j,string &t)
    {
        if(j == -1) return 1;
        if(i == -1) return 0;

        if(s[i] != t[j])
            return countSS(i-1,s,j,t);
        else
            return (countSS(i-1,s,j-1,t) + countSS(i-1,s,j,t));
    }
    int numDistinct(string s, string t) {
        
        int M = s.length();
        int N = t.length();
        return countSS(M-1,s,N-1,t);
    }
};

//Memoization
class Solution {
public:

    int countSS(int i,string&s,int j,string &t,vector<vector<int>>&ans)
    {
        if(j == -1) return 1;
        if(i == -1) return 0;
        if(ans[i][j] != -1) return ans[i][j];
        if(s[i] != t[j])
            ans[i][j]  = countSS(i-1,s,j,t,ans);
        else
            ans[i][j] =  (countSS(i-1,s,j-1,t,ans) + countSS(i-1,s,j,t,ans));

        return ans[i][j];
    }
    int numDistinct(string s, string t) {
        
        int M = s.length();
        int N = t.length();
        vector<vector<int>>ans(M,vector<int>(N,-1));
        return countSS(M-1,s,N-1,t,ans);
    }
};

// Bottom-Top

class Solution {
public:

    unsigned long long int countSS(string&s,string &t,vector<vector<unsigned long long int>>&ans)
    {
        for(int j=0;j<=t.length();j++)
            ans[0][j] = 0;
        for(int i=0;i<=s.length();i++)
            ans[i][0] = 1;
        
        for(int i=1;i<=s.length();i++)
        {
            for(int j=1;j<=t.length();j++)
            {
                if(s[i-1] != t[j-1])
                    ans[i][j] = ans[i-1][j];
                else
                    ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
        }

        return ans[s.length()][t.length()];
    }
    int numDistinct(string s, string t) {
        
        int M = s.length();
        int N = t.length();
        vector<vector<unsigned long long int>>ans(M+1,vector<unsigned long long int>(N+1,0));
        return countSS(s,t,ans);
    }
};