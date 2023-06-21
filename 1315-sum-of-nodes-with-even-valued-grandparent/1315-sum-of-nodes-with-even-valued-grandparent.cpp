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
    int sumEvenGrandparent(TreeNode* root) {
        map<TreeNode*,TreeNode*> mp;
        queue<pair<TreeNode*,TreeNode*>> q;
        int ans=0;
        q.push({root,NULL});
        
        while(!q.empty())
        {
            for(int i=0;i<q.size();i++)
            {
                TreeNode* node=q.front().first;
                TreeNode* parent=q.front().second;
                q.pop();
                
                if(parent!=NULL)
                {
                    if(node->left!=NULL)
                    {
                        mp[node->left]=parent;
                    }
                    if(node->right!=NULL) 
                    {
                        mp[node->right]=parent;
                    }
                }
                
                if(node->left!=NULL)
                {
                    q.push({node->left,node});
                }
                if(node->right!=NULL) 
                {
                    q.push({node->right,node});
                }
            }
        }
        
        for(auto it: mp)
        {
            if(it.second->val % 2==0) ans+=it.first->val;
        }
        return ans;
    }
};