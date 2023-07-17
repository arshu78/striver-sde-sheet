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
    TreeNode* f(int s,int e,vector<int>& in)
    {
        if(s>e) return NULL;
        int mid=(s+e)/2;
        
        TreeNode* root=new TreeNode(in[mid]);
        root->left=f(s,mid-1,in);
        root->right=f(mid+1,e,in);
        
        return root;
        
    }
    void ino(TreeNode* root,vector<int>& in)
    {
        if(root==NULL) return ;
        ino(root->left,in);
        in.push_back(root->val);
        ino(root->right,in);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        ino(root,in);
        
        return f(0,in.size()-1,in);
    }
};