// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
class Solution{
public:

    int solve(int i,int j,int row[],int col[],int N)
    {
        if(i==j) return 0;
        
        int ans = INT_MAX;
        for(int k=i;k<j;k++)
        {
            ans = min(ans,solve(i,k,row,col,N) + solve(k+1,j,row,col,N) + row[i]*col[k]*col[j]);
        }
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        
        int row[N-1];
        int col[N-1];
        
        for(int i=0;i<N-1;i++)
        {
            row[i] = arr[i];
            col[i] = arr[i+1];
        }
        
        return solve(0,N-2,row,col,N-1);
    }
};

// Memoization

class Solution{
public:

    int solve(int i,int j,int row[],int col[],int N,vector<vector<int>>&ans)
    {
        if(i==j) return 0;
        if(ans[i][j] != -1) return ans[i][j];
        ans[i][j] = INT_MAX;
        for(int k=i;k<j;k++)
        {
            ans[i][j] = min(ans[i][j],solve(i,k,row,col,N,ans) + solve(k+1,j,row,col,N,ans) + row[i]*col[k]*col[j]);
        }
        return ans[i][j];
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        
        int row[N-1];
        int col[N-1];
        
        vector<vector<int>>ans(N-1,vector<int>(N-1,-1));
        for(int i=0;i<N-1;i++)
        {
            row[i] = arr[i];
            col[i] = arr[i+1];
        }
        
        return solve(0,N-2,row,col,N-1,ans);
    }
};
