// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
// Maximum Sum Subsequence

//TOP-BOTTOM

class Solution
{
    public:
    //Function to find the maximum money the thief can get.\
    
    vector<int>ans;
    int FindMax(int arr[], int n,int i)
    {
        if(i >= n)
            return 0;
        if(ans[i] != -1)
            return ans[i];
            
        int first = arr[i] + FindMax(arr,n,i+2);
        int second = FindMax(arr,n,i+1);
        
        ans[i] = max(first,second);
        
        return ans[i];
        
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        
        ans = vector<int>(n,-1);
        
        int x = FindMax(arr,n,0);
        
        // for(int i=0;i<n;i++)
        //     cout<<ans[i]<<"-";
        return ans[0];
    }
};

// Bottom-Up

class Solution
{
    public:
    //Function to find the maximum money the thief can get.\
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n < 1)
            return 0;
        int first = arr[0];
        if(n == 1)
            return first;
        int second = max(arr[0],arr[1]);
        
        for(int i=2;i<n;i++)
        {
            int curr = max(arr[i] + first , second);
            
            first = second;
            second = curr;
        }
        
        return second;
        
        
    }
};