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
    int f(TreeNode* root,int& sum)
    {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        
        int left=f(root->left,sum);
        int right=f(root->right,sum);
        sum+=abs(left-right);
        
        return left+ right + root->val;
    }
    int findTilt(TreeNode* root) {
       
        int sum=0;
        f(root,sum);
        return sum;
    }
};