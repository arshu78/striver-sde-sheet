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
    
    void f(TreeNode* root,bool flag,int cur,int &maxi)
    {
        if(root==NULL)
        {
            maxi=max(maxi,cur);
            return;
        }
        
        maxi=max(maxi,cur);
        
        if(flag==false)
        {
           
                f(root->left,!flag,cur+1,maxi);
                f(root->right,flag,0,maxi);
           
        }
        else
        {
              f(root->right,!flag,cur+1,maxi);
                 f(root->left,flag,0,maxi);
           
        }
    }
    int longestZigZag(TreeNode* root) {
        int cur=0,maxi=0;
        bool left=true;
        f(root->left,left,cur,maxi);
        f(root->right,!left,cur,maxi);
        return maxi;
    }
};