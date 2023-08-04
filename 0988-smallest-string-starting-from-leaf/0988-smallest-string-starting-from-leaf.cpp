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
    
    void f(TreeNode* root,string s,string &ans)
    {
        if(root==NULL) return;
        
        s.push_back(root->val + 'a');
        
        if(root->left==NULL && root->right==NULL)
        {
            string temp=s;
            reverse(temp.begin(),temp.end());
            
            if(ans.empty() || temp<ans)
            {
                ans=temp;
            }
        }
        
        f(root->left,s,ans);
        f(root->right,s,ans);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans,s;
        
        f(root,s,ans);
        return ans;
    }
};