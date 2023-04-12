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

    pair<int,int> getDiameter(TreeNode *root){
        if(!root){
            return {0,0};
        }

        if(!root->left and !root->right){
            return {1,1};
        }

        pair<int,int> LST = getDiameter(root->left);
        pair<int,int> RST = getDiameter(root->right);

        int height = 1 + max(LST.first,RST.first);
        int diameter = max(max(LST.second,RST.second),1+LST.first+RST.first);

        return {height,diameter};

    }

    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> Result = getDiameter(root);

        return Result.second-1;
    }
};

//this is O(N) approach

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