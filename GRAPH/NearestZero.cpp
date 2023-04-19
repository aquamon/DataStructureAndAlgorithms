// https://leetcode.com/problems/01-matrix/

lass Solution {
public:

    struct cell{
        int x;
        int y;
        int dist;
        cell(int X,int Y,int Dist)
        {
            x = X;
            y = Y;
            dist = Dist;
        }
    };

    bool isValid(int X,int Y,int M,int N)
    {
        return (X>=0 and X<M and Y>=0 and Y<N);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int M = mat.size();
        int N = mat[0].size();
        vector<vector<int>>res(M,vector<int>(N,0));
        bool isVis[M][N];

        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
                isVis[i][j] = false;
        }

        queue<cell>Q;
        vector<int>X = {0,0,1,-1};
        vector<int>Y = {1,-1,0,0};

        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(mat[i][j] == 0)
                {
                    Q.push(cell(i,j,0));
                    isVis[i][j] = true;
                }
            }
        }

        while(!Q.empty())
        {
            cell C = Q.front();
            Q.pop();


            for(int i=0;i<4;i++)
            {
                int x = C.x + X[i];
                int y = C.y + Y[i];

                if(isValid(x,y,M,N) and isVis[x][y] == false)
                {
                    isVis[x][y] = true;
                    if(mat[x][y] == 1)
                        res[x][y] = C.dist+1;
                    Q.push(cell(x,y,C.dist+1));
                }
            }

            
        }
        return res;
    }
};