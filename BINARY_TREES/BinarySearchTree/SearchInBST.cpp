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

//https://leetcode.com/problems/search-in-a-binary-search-tree/description/

//Recursive

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;

        if(root->val == val)
            return root;
        
        if(val > root->val)
            return searchBST(root->right,val);
        else
            return searchBST(root->left,val);
    }   
};

//Iterative

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;

        TreeNode *curr = root;

        while(curr)
        {
            if(curr->val == val)
                break;
            else if(curr->val < val)
                curr = curr->right;
            else
                curr = curr->left;
        }
        return curr;
    }   
};