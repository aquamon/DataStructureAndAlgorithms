// https://leetcode.com/problems/number-of-islands/description/



class Solution {
public:

    vector<int> X = {1,-1,0,0};
    vector<int> Y = {0,0,1,-1};
    bool isValid(int x,int y, int M, int N)
    {
        return (x >=0 and x < M and y >=0 and y < N);
    }

    void dfs(int x,int y,vector<vector<char>>& grid,int M,int N,vector<vector<bool>>&isVis)
    {
        if(isVis[x][y])
            return;
        isVis[x][y] = true;
        
        for(int i=0;i<4;i++)
        {
            int p = x+X[i];
            int q = y+Y[i];
            if(isValid(p,q,M,N) and grid[x][y] == '1')
                dfs(p,q,grid,M,N,isVis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int M = grid.size();
        int N = grid[0].size();

        int count = 0;

        vector<vector<bool>>isVis(M,vector<bool>(N,false));

        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(isVis[i][j] == false and grid[i][j] == '1')
                {
                    count++;
                    // isVis[i][j] = true;
                    // grid[i][j] = '2';
                    // for(int k = 0 ; k < 4 ; k++)
                    // {
                    //     int x = i+X[k];
                    //     int y = j+Y[k];

                        // if(isValid(x,y,M,N) and grid[x][y] == '1')
                            dfs(i,j,grid,M,N,isVis);
                    // }
                }
            }
        }

         for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

        return count;

    }
};

class Solution {
public:

    vector<int> X = {1,-1,0,0};
    vector<int> Y = {0,0,1,-1};
    bool isValid(int x,int y, int M, int N)
    {
        return (x >=0 and x < M and y >=0 and y < N);
    }

    void dfs(int x,int y,vector<vector<char>>& grid,int M,int N)
    {
        if(!isValid(x,y,M,N) or grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        
        for(int i=0;i<4;i++)
        {
            int p = x+X[i];
            int q = y+Y[i];
            dfs(p,q,grid,M,N);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int M = grid.size();
        int N = grid[0].size();
        int count = 0;
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j] == '1')
                {
                   dfs(i,j,grid,M,N);
                   count++;  
                }
                
            }
        }
        return count;
    }
};