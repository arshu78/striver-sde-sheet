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
    TreeNode * build(vector < int > & postorder, int postStart, int postEnd, 
vector < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (postStart > postEnd || inStart > inEnd) return NULL;

  TreeNode * root = new TreeNode(postorder[postEnd]);
  int elem = mp[root -> val];
  int nElem = elem - inStart;

  root -> left = build(postorder, postStart, postStart + nElem - 1, 
  inorder, inStart, elem - 1, mp);
  root -> right = build(postorder, postStart + nElem, postEnd-1, inorder,
  elem + 1, inEnd, mp);

  return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }

        return build(postorder,0,inorder.size()-1,inorder,0,postorder.size()-1,mpp);
    }
};