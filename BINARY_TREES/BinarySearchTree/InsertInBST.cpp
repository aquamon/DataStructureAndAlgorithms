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

//https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val,NULL,NULL);
        TreeNode *parent = NULL;
        TreeNode *curr = root;

        while(curr)
        {
            parent = curr;
            if(curr->val < val )
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }

        if(val < parent->val)
            parent->left = new TreeNode(val,NULL,NULL);
        else
            parent->right = new TreeNode(val,NULL,NULL);
        return root;

    }
};


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *newnode = new TreeNode(val);
        if(!root)
            return newnode;
        
        TreeNode *curr = root;
        while(curr)
        {
            if(curr->val > val)
            {
                if(!curr->left)
                {
                    curr->left = newnode;
                    break;
                }
                else
                    curr = curr->left;
            }
            else if(curr->val < val)
            {
                if(!curr->right)
                {
                    curr->right = newnode;
                    break;
                }
                else
                    curr = curr->right;
            }
        }
        return root;
    }
};