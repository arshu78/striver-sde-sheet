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
    
    class info
    {
        public:
         int maxi;
        int mini;
        int data;
        bool isBst;
        int sum;
    };
    
    info f(TreeNode* root,int &ans)
    {
        if(root==NULL) return {INT_MIN,INT_MAX,0,true,0};
        
        info left=f(root->left,ans);
        info right=f(root->right,ans);
        
        info cur;
        cur.mini=min(root->val,left.mini);
        cur.maxi=max(root->val,right.maxi);
        cur.data=root->val;
        cur.sum=left.sum+right.sum+root->val;
    
        
        if(left.isBst && right.isBst && root->val>left.maxi && root->val<right.mini)
        {
            cur.isBst=true;
        }
        else
        {
            cur.isBst=false;
        }
        
        if(cur.isBst)
        {
            ans=max(ans,cur.sum);
        }
        
        return cur;
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        f(root,ans);
        
        return ans;
    }
};