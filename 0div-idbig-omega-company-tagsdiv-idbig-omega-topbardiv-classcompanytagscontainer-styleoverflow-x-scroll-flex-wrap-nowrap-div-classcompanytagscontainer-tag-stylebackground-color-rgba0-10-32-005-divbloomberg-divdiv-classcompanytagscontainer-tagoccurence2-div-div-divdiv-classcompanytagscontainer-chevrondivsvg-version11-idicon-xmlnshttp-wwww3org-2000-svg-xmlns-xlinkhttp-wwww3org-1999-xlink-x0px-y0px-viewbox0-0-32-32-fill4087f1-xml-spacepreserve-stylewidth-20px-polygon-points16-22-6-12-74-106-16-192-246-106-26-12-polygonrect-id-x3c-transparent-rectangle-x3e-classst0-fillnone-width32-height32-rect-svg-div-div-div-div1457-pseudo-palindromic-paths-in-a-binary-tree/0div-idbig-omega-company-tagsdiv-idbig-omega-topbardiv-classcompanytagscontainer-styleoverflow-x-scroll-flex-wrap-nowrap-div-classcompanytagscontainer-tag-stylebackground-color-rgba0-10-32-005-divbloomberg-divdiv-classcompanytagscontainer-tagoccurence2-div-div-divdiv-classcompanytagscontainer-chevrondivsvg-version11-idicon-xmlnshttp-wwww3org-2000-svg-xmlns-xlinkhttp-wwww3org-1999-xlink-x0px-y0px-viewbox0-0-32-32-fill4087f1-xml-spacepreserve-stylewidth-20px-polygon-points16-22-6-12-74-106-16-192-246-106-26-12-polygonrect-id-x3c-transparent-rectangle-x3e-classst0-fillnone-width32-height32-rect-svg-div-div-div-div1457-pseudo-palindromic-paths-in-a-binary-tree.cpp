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
    void f(TreeNode* root,map<int,int>& mp,int &ans)
    {
        mp[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
           
            int cnt=0;
            for(auto it:mp){
                if(it.second%2!=0) cnt++;
            }
            if(cnt<=1) ans++;
            mp[root->val]--;
            return;
        }
        
           if(root->left) f(root->left,mp,ans);
           if(root->right) f(root->right,mp,ans);
            mp[root->val]--;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int> mp;
        
        int ans=0;
        f(root,mp,ans);
        return ans;
    }
};