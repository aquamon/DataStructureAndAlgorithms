// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

vector<vector<int>>MAT;
class Solution {
public:

    
    struct cmp{
        bool operator()(pair<int,int> &x, pair<int,int>&y)
        {
            return MAT[x.first][x.second] > MAT[y.first][y.second];
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        MAT = matrix;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>PQ;

        PQ.push({0,0});

        map<pair<int,int>,bool>M;
        M[{0,0}] = true;

        int count = 0;
        while(count < k)
        {
            pair<int,int> P = PQ.top();
            PQ.pop();

            if(P.first + 1 < matrix.size() and M.find({P.first+1,P.second}) == M.end())
            {
                PQ.push({P.first+1,P.second});
                M[{P.first+1,P.second}] = true;
            }

             if(P.second + 1 < matrix.size() and M.find({P.first,P.second+1}) == M.end())
            {
                PQ.push({P.first,P.second+1});
                M[{P.first,P.second+1}] = true;
            }

            if(count + 1 == k)
                return matrix[P.first][P.second];

            count++;
        }
        return -1;
    }
};