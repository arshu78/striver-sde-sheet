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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
         q.push(NULL);
        int cnt=0;
        while(!q.empty())
        {
            TreeNode* a = q.front();
                q.pop();
            vector<int> temp;
            while(a!=NULL)
            {
                temp.push_back(a->val);
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
                a=q.front();
                q.pop();
            }
             if(!q.empty()) q.push(NULL);
            unordered_map<int,int> mp;
            for(int i=0;i<temp.size();i++)
            {
                mp[temp[i]]=i;
            }
            sort(temp.begin(),temp.end());
            int i=0;
            while(i<temp.size())
            {
                if(i!=mp[temp[i]])
                {
                    cnt++;
                    swap(temp[i],temp[mp[temp[i]]]);
                }
                else i++;
            }
        }
        return cnt;
    }
};