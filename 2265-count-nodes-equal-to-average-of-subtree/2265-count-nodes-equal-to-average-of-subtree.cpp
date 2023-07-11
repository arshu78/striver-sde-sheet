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
    pair<int,int> f(TreeNode* root,int& ans)
    {
     if(!root)return pair{0,0};
        pair<int,int> l=f(root->left,ans);
        pair<int,int> r=f(root->right,ans);
        if((l.first+r.first+root->val)/(l.second+r.second+1)==root->val)ans++;
        return pair{l.first+r.first+root->val,l.second+r.second+1};
        
        
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0,sum=0;
        
        f(root,ans);
        
        return ans;
    }
};