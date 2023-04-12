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

    pair<bool,int> getBalanced(TreeNode *root){
        if(!root){
            return {true,0};
        }
        if(!root->left and !root->right){
            return {true,1};
        }

        pair<bool,int> LST = getBalanced(root->left);
        pair<bool,int> RST = getBalanced(root->right);

        int height = 1 + max(LST.second,RST.second);
        bool isBalanced = LST.first && RST.first && (abs(LST.second-RST.second) < 2);

        return {isBalanced,height};
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        pair<bool,int> Result = getBalanced(root);

        return Result.first;
    }
};