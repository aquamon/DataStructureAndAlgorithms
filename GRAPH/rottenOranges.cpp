// https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:

    struct cell{
        int x,y,time;
        cell(int X,int Y,int D){
            x = X;
            y = Y;
            time = D;
        }
    };

    bool isValid(int x,int y, int M,int N)
    {
        return (x >= 0 and x < M and y>=0 and y < N);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();

        bool isVis[M][N];

        queue<cell>Q;

        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                isVis[i][j] = false;
                if(grid[i][j] == 2)
                {
                    isVis[i][j] = true;
                    Q.push(cell(i,j,0));
                }
            }
        }

        vector<int>X = {0,0,1,-1};
        vector<int>Y = {1,-1,0,0};
        int ans = 0;
        while(!Q.empty())
        {
            cell C = Q.front();
            Q.pop();

            for(int i=0;i<4;i++)
            {
                int x = C.x + X[i];
                int y = C.y + Y[i];

                if(isValid(x,y,M,N) && isVis[x][y] == false && grid[x][y] == 1)
                {
                    isVis[x][y] = true;
                    ans = max(ans,C.time+1);
                    grid[x][y] = 2;
                    Q.push(cell(x,y,C.time+1));
                }
            }


        }
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return ans;
            
    }
};