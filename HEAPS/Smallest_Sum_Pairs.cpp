// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

class Solution {
public:

    struct data{
        int i,j,sum;
    };

    struct  cmp{
        bool operator()(data &A,data &B)
        {
            return A.sum > B.sum;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        

        vector<vector<int>>ans;


        priority_queue<data,vector<data>,cmp>PQ;

        map<pair<int,int>,bool> M;

        PQ.push({0,0,nums1[0]+nums2[0]});

        M[{0,0}] = true;


        while(PQ.size() > 0 and k--)
        {
            data D = PQ.top();
            PQ.pop();

            ans.push_back({nums1[D.i],nums2[D.j]});

            if(D.i+1 < nums1.size() and M.find({D.i+1,D.j}) == M.end())
            {
                PQ.push({D.i+1,D.j,nums1[D.i+1]+nums2[D.j]});
                M[{D.i+1,D.j}] = true;
            }

            if(D.j+1 < nums2.size() and M.find({D.i,D.j+1}) == M.end())
            {
                PQ.push({D.i,D.j+1,nums1[D.i]+nums2[D.j+1]});
                M[{D.i,D.j+1}] = true;
            }
        }
        return ans;
    }
};