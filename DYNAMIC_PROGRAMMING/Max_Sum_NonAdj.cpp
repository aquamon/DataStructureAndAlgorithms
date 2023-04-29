// https://practice.geeksforgeeks.org/problems/adjacents-are-not-allowed3528/1

class Solution{
public:
    int maxSum(int N, vector<vector<int>> mat)
    {
        // code here
        
        int first = max(mat[0][0],mat[1][0]);
        
        if(N == 1)
            return first;
        
        int second = max(first,max(mat[0][1],mat[1][1]));
        
        for(int i=2;i<N;i++)
        {
            int curr = max(max(mat[0][i],mat[1][i])+first,second);
            
            first = second;
            
            second = curr;
        }
        
        return second;
    }
};