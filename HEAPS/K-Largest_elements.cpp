// https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1

class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        
        priority_queue<int> PQ(arr,arr+n);
        
        vector<int>ans;
        while(k--)
        {
            ans.push_back(PQ.top());
            PQ.pop();
        }
        
        return ans;
    }
};