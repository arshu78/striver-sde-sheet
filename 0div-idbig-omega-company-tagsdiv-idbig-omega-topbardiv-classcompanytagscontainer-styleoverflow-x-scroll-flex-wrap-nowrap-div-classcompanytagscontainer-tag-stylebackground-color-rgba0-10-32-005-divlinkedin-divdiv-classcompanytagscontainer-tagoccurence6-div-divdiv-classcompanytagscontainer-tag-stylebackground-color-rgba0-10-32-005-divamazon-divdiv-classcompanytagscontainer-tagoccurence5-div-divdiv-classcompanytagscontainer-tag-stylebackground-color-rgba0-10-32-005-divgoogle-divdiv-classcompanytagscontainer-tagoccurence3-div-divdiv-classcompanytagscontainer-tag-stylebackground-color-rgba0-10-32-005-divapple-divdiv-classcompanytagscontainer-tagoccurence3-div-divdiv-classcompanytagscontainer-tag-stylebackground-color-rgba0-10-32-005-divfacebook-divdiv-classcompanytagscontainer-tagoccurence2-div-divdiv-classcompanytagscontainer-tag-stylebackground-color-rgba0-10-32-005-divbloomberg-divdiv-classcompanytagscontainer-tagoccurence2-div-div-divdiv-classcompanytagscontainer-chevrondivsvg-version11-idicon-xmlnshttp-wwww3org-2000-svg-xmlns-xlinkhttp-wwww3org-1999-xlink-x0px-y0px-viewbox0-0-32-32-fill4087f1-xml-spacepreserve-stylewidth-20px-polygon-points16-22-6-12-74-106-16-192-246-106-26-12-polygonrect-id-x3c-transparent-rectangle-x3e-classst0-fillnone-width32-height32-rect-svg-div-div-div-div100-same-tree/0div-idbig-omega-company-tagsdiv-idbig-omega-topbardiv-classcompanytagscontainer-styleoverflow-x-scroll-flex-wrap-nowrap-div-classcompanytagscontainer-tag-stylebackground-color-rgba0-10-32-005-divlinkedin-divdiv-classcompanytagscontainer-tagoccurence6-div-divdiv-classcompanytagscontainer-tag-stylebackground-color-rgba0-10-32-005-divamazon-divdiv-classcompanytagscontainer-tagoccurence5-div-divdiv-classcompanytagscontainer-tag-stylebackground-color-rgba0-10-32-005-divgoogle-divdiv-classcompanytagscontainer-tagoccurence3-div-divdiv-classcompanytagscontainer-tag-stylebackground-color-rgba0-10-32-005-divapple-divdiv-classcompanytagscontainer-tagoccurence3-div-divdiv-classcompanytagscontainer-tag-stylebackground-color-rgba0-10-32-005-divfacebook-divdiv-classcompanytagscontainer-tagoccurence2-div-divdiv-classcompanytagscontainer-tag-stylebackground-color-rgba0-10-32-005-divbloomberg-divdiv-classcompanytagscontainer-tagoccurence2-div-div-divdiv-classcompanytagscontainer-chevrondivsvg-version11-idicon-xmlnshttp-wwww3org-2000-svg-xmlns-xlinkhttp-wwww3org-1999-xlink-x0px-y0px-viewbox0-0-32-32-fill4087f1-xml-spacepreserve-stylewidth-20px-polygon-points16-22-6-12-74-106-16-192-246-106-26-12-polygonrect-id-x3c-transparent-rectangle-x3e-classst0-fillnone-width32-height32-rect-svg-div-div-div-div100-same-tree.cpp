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
    bool f(TreeNode* a,TreeNode* b)
    {
        if(a==NULL || b==NULL) return a==b;
        if(a->val!=b->val) return false;
        
        bool p=f(a->left,b->left);
        if(!p) return false;
        
        bool q=f(a->right,b->right);
        if(!q) return false;
        
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return f(p,q);
    }
};