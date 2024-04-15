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
    void f(TreeNode* root,string st,long long int &sum)
    {
        if(!root) return;
        if(root->left==NULL && root->right==NULL)
        {
           // reverse(st.begin(),st.end());
            long long int t=stoi(st);
            sum+=t;
        }
        if(root->left)
        {
            st.push_back(root->left->val + '0');
            f(root->left,st,sum);
            st.pop_back();
        }
          if(root->right)
        {
            st.push_back(root->right->val + '0');
            f(root->right,st,sum);
            st.pop_back();
        }
        return;
    }
    int sumNumbers(TreeNode* root) {
        string st="";
        st.push_back(root->val + '0');
        long long int sum=0;
        f(root,st,sum);
        return sum;
    }
};