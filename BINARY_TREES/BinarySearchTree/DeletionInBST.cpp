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

// https://leetcode.com/problems/delete-node-in-a-bst/description/
class Solution {
public:
    bool isLeafNode(TreeNode *node)
    {
        if(!node) return false;
        return (!node->left and !node->right);
    }

    bool hasSingleChild(TreeNode *node)
    {
        return (!node->left and node->right) or (!node->right and node->left);
    }

    TreeNode* deletSingleChild(TreeNode* parent,TreeNode *node)
    {
        if(parent->left == node)
        {
            if(node and node->left)
            {
                parent->left = node->left;
                node->left = NULL;
            }
            else if(node)
            {
                parent->left = node->right;
                node->right = NULL;
            }
        }
        else
        {
            if(node and node->left)
            {
                parent->right = node->left;
                node->left = NULL;
            }
            else if(node)
            {
                parent->right = node->right;
                node->right = NULL;
            }
        }

        return node;

    }

    TreeNode* deleteLeafNode(TreeNode* parent,TreeNode* node)
    {
        if(parent->left == node)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        return node;
    }

    TreeNode* deleteDoubleChildNode(TreeNode *parent, TreeNode* node)
    {
        TreeNode *curr = node;
        TreeNode *pred = curr->left;
        while(pred->right)
        {
            curr = pred;
            pred = curr->right;
        }

        TreeNode *n1;
        if(isLeafNode(pred))
            n1 = deleteLeafNode(curr,pred);
        else
            n1 = deletSingleChild(curr,pred);
        
        if(parent and parent->left == node)
            parent->left = n1;
        else if(parent)
            parent->right = n1;
        
        if(node and n1)
        {
            n1->left = node->left;
            n1->right = node->right;
            node->left = NULL;
            node->right = NULL;
        }

       
        return node;
    }

    TreeNode* deleteRoot(TreeNode *root)
    {
        if(isLeafNode(root))
        {
            delete root;
            return NULL;
        }
        if(hasSingleChild(root))
        {
            TreeNode *ans = root->left ? root->left : root->right;
            delete root;
            return ans;
        }

        TreeNode * ans = root->left;
        while(ans->right)
            ans = ans->right;
        
        TreeNode *node = deleteDoubleChildNode(NULL,root);
        delete node;
        return ans;
    }
    pair<TreeNode*,TreeNode*> getNodeAndParent(TreeNode* root, int key)
    {
        TreeNode *node = root;
        TreeNode *parent = NULL;
        while(node)
        {
            if(node->val == key)
                break;
            parent = node;
            if(node->val < key)
                node = node->right;
            else
                node = node->left;
        }
        return {node,parent};
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        pair<TreeNode*,TreeNode*> P = getNodeAndParent(root,key);

        if(!P.first)
            return root;
        if(P.first == root)
            return deleteRoot(root);
        
        TreeNode *node;
        if(isLeafNode(P.first))
            node = deleteLeafNode(P.second,P.first);
        
        else if(hasSingleChild(P.first))
            node = deletSingleChild(P.second,P.first);
        else
            node = deleteDoubleChildNode(P.second,P.first);
        
        delete node;

        return root;
    }
};