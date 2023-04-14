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

https://leetcode.com/problems/binary-search-tree-iterator/description/

//This approach is O(N) time and O(N) space
class BSTIterator {
public:
    vector<int>A;
    int c = 0;
    void traverse(TreeNode* root){
        if(!root) return;
        traverse(root->left);
        A.push_back(root->val);
        traverse(root->right);
    } 
    BSTIterator(TreeNode* root) {
        

        
            traverse(root);
        
    }
    
    int next() {
        return A[c++];
    }
    
    bool hasNext() {
        return c<A.size();
    }
};

//This approach is O(N) time and O(H) space
//Amortized complexity of next is O(1)
class BSTIterator {
public:
    stack<TreeNode*>S;
    void traverse(TreeNode* root){
        if(!root) return;

        TreeNode *tmp = root;
        while(tmp)
        {
            S.push(tmp);
            tmp = tmp->left;
        }
    } 
    BSTIterator(TreeNode* root) {
        traverse(root);
    }
    
    int next() {
        TreeNode *T = S.top();
        S.pop();
        TreeNode *tmp = T->right;
        while(tmp)
        {
            S.push(tmp);
            tmp = tmp->left;
        }
        return T->val;
    }
    
    bool hasNext() {
        return !S.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */