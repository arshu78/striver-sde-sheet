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
    int mi(vector<int>& nums)
    {
        int maxi=0;
        for(int i=0;i<nums.size();i++) if(nums[i]>nums[maxi]) maxi=i;
        
        return maxi;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        int m=mi(nums);
        TreeNode* root=new TreeNode(nums[m]);
        vector<int> leftpart,rightpart;
        for(int i=0;i<m;i++) leftpart.push_back(nums[i]);
        for(int i=m+1;i<nums.size();i++) rightpart.push_back(nums[i]);
       
        root->left=constructMaximumBinaryTree(leftpart);
        root->right=constructMaximumBinaryTree(rightpart);
        
        return root;
        
    }
};