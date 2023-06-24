/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ref=NULL;
    void f(TreeNode* a,TreeNode* tar)
    {
        if(a==NULL) return;
        
        if(a->val==tar->val)
        {
            ref=a;
            return;
        }
           
        
        if(a->left!=NULL) f(a->left,tar);
        if(a->right!=NULL) f(a->right,tar);
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        f(cloned,target);
        return ref;
    }
};