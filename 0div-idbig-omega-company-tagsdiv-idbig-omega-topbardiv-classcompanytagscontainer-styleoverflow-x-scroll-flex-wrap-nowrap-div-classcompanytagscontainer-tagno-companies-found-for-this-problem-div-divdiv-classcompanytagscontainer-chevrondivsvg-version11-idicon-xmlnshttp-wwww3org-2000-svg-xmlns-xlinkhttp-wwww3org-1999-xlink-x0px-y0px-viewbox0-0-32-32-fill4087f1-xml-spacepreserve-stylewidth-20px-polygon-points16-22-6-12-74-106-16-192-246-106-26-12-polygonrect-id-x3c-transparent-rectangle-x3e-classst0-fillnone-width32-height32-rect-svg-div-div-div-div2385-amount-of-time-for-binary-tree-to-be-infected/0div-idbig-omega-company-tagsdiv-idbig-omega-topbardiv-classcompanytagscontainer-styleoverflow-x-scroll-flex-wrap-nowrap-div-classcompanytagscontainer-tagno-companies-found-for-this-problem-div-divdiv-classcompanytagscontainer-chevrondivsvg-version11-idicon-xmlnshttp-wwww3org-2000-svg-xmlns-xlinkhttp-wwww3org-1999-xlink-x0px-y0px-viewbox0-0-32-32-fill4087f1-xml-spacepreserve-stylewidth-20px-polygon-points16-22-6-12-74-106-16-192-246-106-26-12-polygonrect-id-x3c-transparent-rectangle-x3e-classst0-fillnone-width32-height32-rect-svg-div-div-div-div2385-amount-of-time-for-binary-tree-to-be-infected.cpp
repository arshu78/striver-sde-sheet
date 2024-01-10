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
    
    int s(TreeNode* root,map<TreeNode*,TreeNode*>& mp,map<TreeNode*,bool>& vis)
    {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vis[root]=true;
        int ans=0;
        while(!q.empty())
        {
            TreeNode* node=q.front().first;
            int time=q.front().second;
            ans=max(ans,time);
            q.pop();
            
            if(node->left && !vis[node->left])
            {
                vis[node->left]=true;
                q.push({node->left,time+1});
            }
            
            
            if(node->right && !vis[node->right])
            {
                vis[node->right]=true;
                q.push({node->right,time+1});
            }
            
            if(mp[node] && !vis[mp[node]])
            {
                vis[mp[node]]=true;
                q.push({mp[node],time+1});
            }
        }
        
        return ans;
    }
    TreeNode* f(TreeNode* root,map<TreeNode*,TreeNode*>& mp,int start,map<TreeNode*,bool>& vis)
    {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty())
        {
            auto a=q.front();
            vis[a]=false;
            q.pop();
            if(a->val==start) res=a;
            
            if(a->left)
            {
                mp[a->left]=a;
                q.push(a->left);
            }
            if(a->right)
            {
                mp[a->right]=a;
                q.push(a->right);
            }
        }
        
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> mp;
        map<TreeNode*,bool> vis;
        TreeNode* first=f(root,mp,start,vis);
        return s(first,mp,vis);
    }
};