// https://leetcode.com/problems/wildcard-matching/description/

// This below code will time out.
class Solution {
public:


    bool isMatching(int i,string &s,int j, string &p,int lastIndx)
    {
        if(i == -1)
        {
            return j<=lastIndx;
        }
        if(j== -1)
            return false;
        
        if(p[j] == '?')
            return isMatching(i-1,s,j-1,p,lastIndx);
        if(p[j] == '*')
            return (isMatching(i,s,j-1,p,lastIndx) || isMatching(i-1,s,j,p,lastIndx));
        
        else
            return (s[i] == p[j] && isMatching(i-1,s,j-1,p,lastIndx));
    }
    bool isMatch(string s, string p) {
        
        int i=0;
        int lastIndx;
        while(i<p.length())
        {
            if(p[i] == '*')
                i++;
            else
                break;
        }
        lastIndx = i-1;
        return isMatching(s.length()-1,s,p.length()-1,p,lastIndx);
    }
};

// Memoization

class Solution {
public:

    int isMatching(int i,string &s,int j, string &p,int lastIndx,vector<vector<int>>&ans)
    {
        if(i == -1)
        {
            return j<=lastIndx;
        }
        if(j== -1)
            return false;
        if(ans[i][j] != -1)
            return ans[i][j];
        if(p[j] == '?')
            return ans[i][j] = isMatching(i-1,s,j-1,p,lastIndx,ans);
        if(p[j] == '*')
            return ans[i][j] = (isMatching(i,s,j-1,p,lastIndx,ans) || isMatching(i-1,s,j,p,lastIndx,ans));
        
        else
            return ans[i][j] =  (s[i] == p[j] && isMatching(i-1,s,j-1,p,lastIndx,ans));
        
        return ans[i][j];
    }
    bool isMatch(string s, string p) {
        
        int i=0;
        int lastIndx=-1;
        while(i<p.length())
        {
            if(p[i] == '*')
                i++;
            else
                break;
        }
        lastIndx = i-1;
        int M = s.length();
        int N = p.length();
        vector<vector<int>>ans(M,vector<int>(N,-1));
        return isMatching(M-1,s,N-1,p,lastIndx,ans);
    }
};

// Bottop - Top

class Solution {
public:

    int isMatching(string &s,string &p,int lastIndx,vector<vector<int>>&ans)
    {
        ans[0][0] = 1;
        for(int j=1;j<=p.length();j++)
        {
            if(p[j-1] == '*')
                ans[0][j] = ans[0][j-1];
        }
      

        for(int i=1;i<=s.length();i++)
        {
            for(int j=1;j<=p.length();j++)
            {
                if(p[j-1] == '?')
                {
                     ans[i][j] = ans[i-1][j-1];
                }
                else if(p[j-1] == '*')
                {
                     ans[i][j] = (ans[i][j-1] or ans[i-1][j]);
                }
                else
                {
                     ans[i][j] = ((s[i-1] == p[j-1]) && ans[i-1][j-1]) ? 1:0;
                }
            }
        }
        return ans[s.length()][p.length()];
    }
    bool isMatch(string s, string p) {
        
        int i=0;
        int lastIndx=-1;
        while(i<p.length())
        {
            if(p[i] == '*')
                i++;
            else
                break;
        }
        lastIndx = i-1;
        int M = s.length();
        int N = p.length();
        vector<vector<int>>ans(M+1,vector<int>(N+1,0));
        return isMatching(s,p,lastIndx,ans);
    }
};

