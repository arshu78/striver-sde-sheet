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
    unordered_map<TreeNode*,int> depth;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL) return NULL;
        
        int l=cnt(root->left);
        int r=cnt(root->right);
        
        if(l==r) return root;
        else if(l<r) return lcaDeepestLeaves(root->right);
        else return lcaDeepestLeaves(root->left);
    }
    
    int cnt(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        // if(depth.count(root)==0) 
        // {
        return depth[root]= 1 + max(cnt(root->left),cnt(root->right));
       // }
        
     //   return depth[root];
    }
};