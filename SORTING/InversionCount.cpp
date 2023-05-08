class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long  count = 0;
    void merge(long long arr[],int start,int mid,int end)
    {
        vector<long long >ans;
        
        int i=start , j=mid+1;
        
        while(i<=mid and j<=end)
        {
            if(arr[i] <= arr[j])
            {
                ans.push_back(arr[i++]);
            }
            else
            {
                count += mid-i+1;
                ans.push_back(arr[j++]);
            }
        }
        
        while(i<=mid)
        {
            ans.push_back(arr[i++]);
        }
        while(j<=end)
        {
            ans.push_back(arr[j++]);
        }
        
        for(int i=start;i<=end;i++)
        {
            arr[i] = ans[i-start];
        }
    }
    void mergeSort(long long arr[],int start,int end)
    {
        if(start >= end)
            return;
        
        int mid = (start+end)/2;
        
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        
        
        mergeSort(arr,0,N-1);
        return count;
    }

};