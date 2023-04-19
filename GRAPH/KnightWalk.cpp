// https://practice.geeksforgeeks.org/problems/knight-walk4521/1

class Solution {
public:
    
    struct cell{
    int x, y, dis;
    cell(int a,int b,int c){
      x = a;
      y = b;
      dis = c;
    } 
};
bool isSafe(int x,int y,int N,int M)
{
    return (x >0 && x <= N && y > 0 && y <= M);
}
int Solve(int N,int M,int s1,int s2,int d1,int d2)
{
   bool visit[N+1][M+1];
   for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
        visit[i][j] = false;
   
   int X[8] = {2, 2, -2, -2, 1, 1, -1, -1};
   int Y[8] = {-1, 1, 1, -1, 2, -2, 2, -2};
    
    queue<cell>Q;
    Q.push(cell(s1,s2,0));
    visit[s1][s2] = true;
    while(!Q.empty())
    {
        cell T = Q.front();
        Q.pop();
        
        if(T.x == d1 && T.y == d2)
            return T.dis;
        
        for(int i=0;i<8;i++)
        {
            int x1 = T.x + X[i];
            int y1 = T.y + Y[i];
            if(isSafe(x1,y1,N,M) && !visit[x1][y1])
            {
               visit[x1][y1] = true;
               Q.push(cell(x1,y1,T.dis+1));
            }
        }
    }
    return -1;
}
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    return Solve(N,N,KnightPos[0],KnightPos[1],TargetPos[0],TargetPos[1]);
	}
};