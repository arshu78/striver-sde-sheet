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
    
    void f(TreeNode* root,int i,int &l,int &ans)
    {
        if(!root) return;
        if(i>l)
        {
            ans=root->val;
            l=i;
        }
        
        f(root->left,i+1,l,ans);
        
        f(root->right,i+1,l,ans);
    } 
    int findBottomLeftValue(TreeNode* root) {
        int cur=1,max=0,ans=0;
        f(root,cur,max,ans);
        return ans;
    }
};