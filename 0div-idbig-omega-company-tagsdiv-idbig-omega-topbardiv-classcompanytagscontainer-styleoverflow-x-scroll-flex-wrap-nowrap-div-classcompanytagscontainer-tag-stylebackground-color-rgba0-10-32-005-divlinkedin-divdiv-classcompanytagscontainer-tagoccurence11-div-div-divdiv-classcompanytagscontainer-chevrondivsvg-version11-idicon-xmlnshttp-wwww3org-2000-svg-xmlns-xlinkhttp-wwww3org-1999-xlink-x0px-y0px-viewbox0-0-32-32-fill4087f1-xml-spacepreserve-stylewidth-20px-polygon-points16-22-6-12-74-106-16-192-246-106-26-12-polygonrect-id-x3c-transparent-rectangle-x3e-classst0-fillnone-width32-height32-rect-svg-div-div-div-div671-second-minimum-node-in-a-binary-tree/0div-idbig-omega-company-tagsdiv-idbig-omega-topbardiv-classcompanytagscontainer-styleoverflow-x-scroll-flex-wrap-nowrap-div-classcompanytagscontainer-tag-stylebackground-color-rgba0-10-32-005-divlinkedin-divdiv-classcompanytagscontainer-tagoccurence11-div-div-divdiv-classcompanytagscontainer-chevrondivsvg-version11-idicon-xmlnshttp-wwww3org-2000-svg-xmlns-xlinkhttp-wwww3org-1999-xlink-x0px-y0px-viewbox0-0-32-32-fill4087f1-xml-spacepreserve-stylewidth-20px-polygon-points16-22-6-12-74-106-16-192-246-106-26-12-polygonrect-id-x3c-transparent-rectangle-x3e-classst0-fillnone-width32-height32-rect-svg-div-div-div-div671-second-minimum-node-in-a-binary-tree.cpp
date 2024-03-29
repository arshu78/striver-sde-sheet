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
     set<int>s;
    void result(TreeNode* root){
        if(root==0){
            return;
        }
        s.insert(root->val);
        result(root->left);
        result(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(root==0) return -1;
        result(root);
        set<int>::iterator itr=s.begin();
        itr++;
        if(s.size()>1) return *itr;
        return -1;
    }
};