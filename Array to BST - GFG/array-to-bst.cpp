//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    class Node{
        public:
      int data;
      Node* left;
      Node* right;
      
      Node(int x)
      {
          this->data=x;
          this->left=NULL;
          this->right=NULL;
      }
    };
     Node* f(int s,int e,vector<int>& nums)
    {
        if(s>e) return NULL;
        int mid=(s+e)/2;
        
        Node* root=new Node(nums[mid]);
        root->left=f(s,mid-1,nums);
        root->right=f(mid+1,e,nums);
        
        return root;
    }
    void pre(Node* root,vector<int>& r)
    {
        if(root==NULL) return;
        r.push_back(root->data);
        pre(root->left,r);
        pre(root->right,r);
    }
    
    vector<int> sortedArrayToBST(vector<int>& nums) {
        Node* root=f(0,nums.size()-1,nums);
        
        vector<int> temp;
        pre(root,temp);
        return temp;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends