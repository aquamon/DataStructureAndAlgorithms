// https://leetcode.com/problems/n-queens/description/

class Solution {
public:

    bool isSafe(int r,int c,int N,vector<vector<int>>&board)
    {
        int x = r-1;

        while(x >= 0)
        {
            if(board[x][c] == 1)
                return false;
            x--;
        }

        x = r-1;
        int y = c-1;

        while(x >=0 and y >= 0)
        {
            if(board[x][y] == 1)
                return false;
            x--;
            y--;
        }

        x = r-1;
        y = c+1;

        while(x >=0 and y < N)
        {
            if(board[x][y] == 1)
                return false;
            x--;
            y++;
        }

        return true;

    }
    void SolveNQ(int r,vector<vector<string>>&res,int N,vector<string>&temp,vector<vector<int>>&board)
    {
        if(r == N)
        {
            res.push_back(temp);
            return;
        }

        for(int c=0;c<N;c++)
        {
            if(isSafe(r,c,N,board))
            {
                string S = "";
                for(int k=0;k<N;k++)
                    S.push_back('.');
                S[c] = 'Q';
                temp.push_back(S);
                
                board[r][c] = 1;
                SolveNQ(r+1,res,N,temp,board);
                board[r][c] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>res;
        vector<vector<int>>board(n,vector<int>(n,'0'));
        if(n == 2 or n == 3)
        {
            return res;
        }
        vector<string>temp;
        SolveNQ(0,res,n,temp,board);
        return res;
    }
};