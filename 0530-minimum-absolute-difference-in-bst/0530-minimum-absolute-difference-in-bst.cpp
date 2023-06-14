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
    void f(TreeNode* root,vector<int> & pq)
    {
        if(root==NULL) return;
       
        f(root->left,pq);
         pq.push_back(root->val);
        f(root->right,pq);
    }
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL || root->left==NULL && root->right==NULL) return 0;
        vector<int> ans;
        f(root,ans);
        int mini=INT_MAX;
        
       for(int i=1;i<ans.size();i++)
       {
           mini=min(mini,abs(ans[i]-ans[i-1]));
       }
      
        return mini;
    }
};