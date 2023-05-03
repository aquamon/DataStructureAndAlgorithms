// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:

    string find_palindrome(string &s,int k,int l)
    {
        if(k < 0 or l >= s.length())
            return "";
        
        while(k >=0 and l < s.length() and s[k] == s[l])
        {
            
                k--;
                l++;
            
        }
      
        if(k<0)
        {
            return s.substr(0,l);
        }
        if(l>=s.length())
        {
            
                return s.substr(k+1,string::npos);
        }
        return s.substr(k+1,l-k-1);


    }
    pair<string,int> odd(string &s)
    {
        string ans = "";
        for(int i=0;i<s.length();i++)
        {
            string curr_ans = s.substr(i,1);
            int k = i-1 , l = i+1;

            string look = find_palindrome(s,k,l);
            if(look.length()<1 and ans.length() < 1)
            {
               ans = curr_ans;
            }
            else if(look.length() > ans.length())
            {
                ans = look;
            }

        }

        return {ans,ans.length()};
    }
    pair<string,int> even(string &s)
    {
        string ans = "";
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i] != s[i+1])
                continue;
            string curr_ans = s.substr(i,2);
            int k = i-1 , l = i+2;

            string look = find_palindrome(s,k,l);

            if(look.length()<1 and ans.length() < 1)
            {
               ans = curr_ans;
            }
            else if(look.length() > ans.length())
            {
                ans = look;
            }
            
        }
        
        return {ans,ans.length()};
    }
    string longestPalindrome(string s) {
        
        if(s.length() == 1)
            return s;
        
        pair<string,int> Odd = odd(s);
        pair<string,int> Even = even(s);

        if(Odd.second > Even.second)
            return Odd.first;
        else
            return Even.first;
    }
};