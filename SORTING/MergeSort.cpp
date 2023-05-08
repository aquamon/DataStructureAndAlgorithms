// https://practice.geeksforgeeks.org/problems/merge-sort/1
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         
         vector<int>ans;
         
         int i=l , j=m+1;
         
         while(i<=m and j <=r)
         {
             if(arr[i] <= arr[j])
             {
                 ans.push_back(arr[i++]);
             }
             else
             {
                 ans.push_back(arr[j++]);
             }
         }
         
         while(i<=m)
         {
             ans.push_back(arr[i++]);    
         }
         while(j <= r)
         {
             ans.push_back(arr[j++]);
         }
         
         for(int i=l;i<=r;i++)
         {
             arr[i] = ans[i-l]; 
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        
        if(l>=r)
            return;
        
        
        int mid = (r+l)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};