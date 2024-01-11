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
    void f(TreeNode* root,int& ans,int maxi,int mini)
    {
        if(root==NULL) return;
        
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        ans=max(ans,abs(mini-maxi));
        
        f(root->left,ans,maxi,mini);
        f(root->right,ans,maxi,mini);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxi=0;
        f(root,maxi,INT_MIN,INT_MAX);
        return maxi;
    }
};