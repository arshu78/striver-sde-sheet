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
    void f(TreeNode* root,int &sum,bool isleft)
    {
        if(!root) return;
        
        if(root->left==NULL && root->right==NULL && isleft) sum+=root->val;
        f(root->left,sum,true);
        f(root->right,sum,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        f(root,sum,false);
        return sum;
    }
};