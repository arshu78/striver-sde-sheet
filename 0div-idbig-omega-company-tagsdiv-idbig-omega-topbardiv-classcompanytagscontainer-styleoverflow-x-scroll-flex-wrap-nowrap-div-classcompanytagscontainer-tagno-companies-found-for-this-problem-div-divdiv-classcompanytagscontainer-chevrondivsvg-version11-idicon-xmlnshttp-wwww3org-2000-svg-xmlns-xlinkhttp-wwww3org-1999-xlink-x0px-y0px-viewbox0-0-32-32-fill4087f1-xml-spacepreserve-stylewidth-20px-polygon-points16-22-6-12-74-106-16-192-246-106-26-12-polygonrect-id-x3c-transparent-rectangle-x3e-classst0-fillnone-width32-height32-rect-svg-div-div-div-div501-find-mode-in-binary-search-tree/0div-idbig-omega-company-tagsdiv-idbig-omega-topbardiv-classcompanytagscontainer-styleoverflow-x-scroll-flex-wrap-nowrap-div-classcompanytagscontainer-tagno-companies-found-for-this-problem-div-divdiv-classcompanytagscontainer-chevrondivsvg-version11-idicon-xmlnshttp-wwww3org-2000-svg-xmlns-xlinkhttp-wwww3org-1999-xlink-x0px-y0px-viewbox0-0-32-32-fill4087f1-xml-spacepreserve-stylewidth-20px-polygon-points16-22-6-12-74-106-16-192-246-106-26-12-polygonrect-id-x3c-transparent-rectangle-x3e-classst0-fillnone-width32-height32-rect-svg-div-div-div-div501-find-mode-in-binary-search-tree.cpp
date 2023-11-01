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
    void f(TreeNode* root,map<int,int>& mp,int& mx)
    {
        if(root==NULL) return;
        mp[root->val]++;
        mx=max(mx,mp[root->val]);
        f(root->left,mp,mx);
        f(root->right,mp,mx);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        int mx=INT_MIN;
        f(root,mp,mx);
        vector<int> ans;
        for(auto it:mp)
        {
            if(it.second == mx) ans.push_back(it.first);
        }
        return ans;
    }
};