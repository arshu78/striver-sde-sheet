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
    bool f(TreeNode* root,int &last)
    {
        if(root==NULL) return true;
        bool left=f(root->left,last);
        if(left==false) return false;
        
        if(root->val!=last) return false;
        
        bool right=f(root->right,last);
        if(right==false) return false;
        
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        int last=root->val;
        return f(root->left,last) && f(root->right,last);
    }
};