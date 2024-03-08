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
    int f(TreeNode* root,int &ans)
    {
        if(!root) return 0;
        
        int l=f(root->left,ans);
        int r=f(root->right,ans);
        
        int left=0,right=0;
        if(root->left && root->val==root->left->val)
        {
            left=l+1;
        }
        
        if(root->right && root->val==root->right->val)
        {
           right=r+1;
        }
        
        ans=max(ans,left+right);
        
        return max(left,right);
        
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
       f(root,ans);
        return ans;
    }
};