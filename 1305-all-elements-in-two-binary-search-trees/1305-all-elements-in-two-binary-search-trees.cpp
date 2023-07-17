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
    vector<int> merge(vector<int>& a,vector<int>& b)
    {
        vector<int> ans(a.size()+b.size());
        
        int i=0,j=0,k=0;
        while(i<a.size() && j<b.size())
        {
            if(a[i]<b[j])
            {
                ans[k++]=a[i++];
            }
            else
            {
                ans[k++]=b[j++];
            }
        }
        
        while(i<a.size()) ans[k++]=a[i++];
        
        while(j<b.size()) ans[k++]=b[j++];
        
        return ans;
    }
    void ino(TreeNode *root,vector<int>& in)
    {
        if(root==NULL) return;
        ino(root->left,in);
        in.push_back(root->val);
        ino(root->right,in);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> bst1,bst2;
        
        ino(root1,bst1);
        ino(root2,bst2);
        
        return merge(bst1,bst2);
    }
};