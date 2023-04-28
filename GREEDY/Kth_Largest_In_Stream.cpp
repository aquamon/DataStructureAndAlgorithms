// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

class KthLargest {
public:

    priority_queue<int,vector<int>,greater<int>>PQ;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        int i=0;

        for(;i<k and i<nums.size();i++)
        {
            PQ.push(nums[i]);
        }

        for(;i<nums.size();i++)
        {
            if(nums[i] >= PQ.top())
            {
                PQ.pop();
                PQ.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        
        int ans;
        if(PQ.size() == size and val >= PQ.top())
        {
            PQ.pop();
            PQ.push(val);
        }
        if(PQ.size() < size)
        {
            PQ.push(val);
        }
        ans = PQ.top();

        return ans;

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */