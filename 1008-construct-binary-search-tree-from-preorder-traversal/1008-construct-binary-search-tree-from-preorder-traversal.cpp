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
    TreeNode* f(int mini,int maxi,vector<int>& pre,int &i)
    {
        if(i>=pre.size()) return NULL;
        
        if(pre[i]<mini || pre[i]>maxi) return NULL;
        
        TreeNode* root=new TreeNode(pre[i++]);
        root->left=f(mini,root->val,pre,i);
        root->right=f(root->val,maxi,pre,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0,mini=INT_MIN,maxi=INT_MAX;
        return f(mini,maxi,preorder,i);
    }
};