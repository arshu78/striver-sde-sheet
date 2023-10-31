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
    TreeNode* f(TreeNode* root,int start,map<TreeNode*,TreeNode*>& mpp)
    {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target;
        while(!q.empty())
        {
             TreeNode* node=q.front();
            if(node->val==start)
            {
                target=node;
            }
            q.pop();
            if(node->left)
            {
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right)
            {
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
        return target;
    }
    
    int find_maxi(TreeNode* target,map<TreeNode*,TreeNode*> mpp)
{
    queue<TreeNode*> q;
    q.push(target);
    map<TreeNode*,bool> visited;
    visited[target]=true;
    int maxi=0;
    while(!q.empty())
    {
        int size=q.size();
        bool f=false;
        for(int i=0;i<size;i++)
        {
            auto node=q.front();
            q.pop();
            if(node->left && !visited[node->left])
            {
                f=true;
                visited[node->left]=true;
                q.push(node->left);
                
            }
            if(node->right && !visited[node->right])
            {
                f=true;
                visited[node->right]=true;
                q.push(node->right);
            }
            if(mpp[node] && !visited[mpp[node]])
            {
                f=true;
                visited[mpp[node]]=true;
                q.push(mpp[node]);
            }
        }
        if(f) maxi++;
    }
    return maxi;
}
    
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> mp;
        TreeNode* s=f(root,start,mp);
         int maxi=find_maxi(s,mp);
        return maxi;
    }
};