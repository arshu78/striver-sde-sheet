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
    void f(TreeNode* root,string temp,string &ans)
    {
        if(!root) return;
        if(root->left==NULL && root->right==NULL) 
        {
            reverse(temp.begin(),temp.end());
             if(ans.empty() || temp<ans)
            {
                ans=temp;
            }
            return;
        }
        if(root->left)
        {
            temp.push_back('a' + root->left->val);
            f(root->left,temp,ans);
            temp.pop_back();
        }
        if(root->right)
        {
            temp.push_back('a' + root->right->val);
            f(root->right,temp,ans);
            temp.pop_back();
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        string temp="",ans;
        temp.push_back(root->val + 'a');
        f(root,temp,ans);
        return ans;
    }
};