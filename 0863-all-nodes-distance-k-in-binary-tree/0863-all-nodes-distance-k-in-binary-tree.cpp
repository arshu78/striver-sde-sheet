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
    void make_p(TreeNode* root,TreeNode* target, unordered_map<TreeNode*,TreeNode*>& parent_track)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
                TreeNode* node=q.front();
                q.pop();
                if(node->left)
                {
                    parent_track[node->left]=node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    parent_track[node->right]=node;
                    q.push(node->right);
                }
            
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        make_p(root,target,parent_track);
        int cnt=0;
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        while(!q.empty())
        {
            int size=q.size();
            if(cnt++==k) break;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    visited[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right])
                {
                    visited[node->right]=true;
                    q.push(node->right);

                }
                if(parent_track[node] && !visited[parent_track[node]])
                {
                    visited[parent_track[node]]=true;
                    q.push(parent_track[node]);
                }
            }
        }

        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};