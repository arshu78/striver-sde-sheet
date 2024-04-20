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
    int maxi;
    int f(TreeNode* root,map<int,int>& mp)
    {
        if(!root) return 0;
        int left=f(root->left,mp);
        int right=f(root->right,mp);
        
        root->val=left + right + root->val;
        mp[root->val]++;
        maxi=max(maxi,mp[root->val]);
        return root->val;
    }
    // void post(TreeNode* root,vector<int>& ans,map<int,int>& mp)
    // {
    //     if(!root) return;
    //     post(root->left,ans,mp);
    //     post(root->right,ans,mp);
    //     if(mp[root->val]==maxi)
    //     ans.push_back(root->val);
    // }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> mp;
        maxi=INT_MIN;
        f(root,mp);
        vector<int> ans;
        for(auto it:mp) if(it.second==maxi) ans.push_back(it.first);
        return ans;
    }
};