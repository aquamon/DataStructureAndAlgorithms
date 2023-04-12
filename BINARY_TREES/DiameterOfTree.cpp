// https://leetcode.com/problems/diameter-of-binary-tree/description/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        
        return 1 + max(getHeight(root->left),getHeight(root->right));
    }
    int ans = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        int curr_ans = 1+lh+rh;
        ans = max(ans,curr_ans);

        ans = max(ans,diameterOfBinaryTree(root->left));
        ans = max(ans,diameterOfBinaryTree(root->right));

        return ans-1;

    }

    /*
    *This approach is O(N^2);
    */
};
void Solve()
{

}
int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        Solve();
    }
}