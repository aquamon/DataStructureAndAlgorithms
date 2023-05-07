// https://leetcode.com/problems/k-closest-points-to-origin/description/
class Solution {
public:

    bool static cmp(vector<int>&P, vector<int>&Q)
    {
        int x1 = P[0] , y1 = P[1];
        int x2 = Q[0] , y2 = Q[1];

        int d1 = x1*x1 + y1*y1;
        int d2 = x2*x2 + y2*y2;

        return d1 < d2;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>>res;

        sort(points.begin(),points.end(),cmp);

        for(int i=0;i<k;i++)
            res.push_back(points[i]);
        
        return res;
    }
};