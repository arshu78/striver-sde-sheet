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
    int md=INT_MAX;
    
    int f(TreeNode* root)
    {
        if(root==NULL) return 0;
        if(root->left && root->right)
            return min(f(root->left), f(root->right))+1;
        int left=f(root->left);
        int right=f(root->right);
        
        return 1 + max(left,right);
    }
    int minDepth(TreeNode* root) {
        
      return f(root);
      
    }
};