// https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:

    struct comp{
        bool operator()(vector<int> &x, vector<int> &y)
        {
            long d1 = x[0]*x[0] + x[1]*x[1];
            long d2 = y[0]*y[0] + y[1]*y[1];

            return d1 > d2;

        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        

        priority_queue<vector<int>,vector<vector<int>>,comp> PQ (points.begin(),points.end());

        vector<vector<int>>ans;

        while(k--)
        {
            vector<int> TOP = PQ.top();

            ans.push_back(TOP);

            PQ.pop();
        }

        return ans;
    }
};