//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    
    vector<int> solve(vector<int>& a,vector<int>& b)
    {
        vector<int> ans(a.size()+b.size());
        
        int i=0,j=0,k=0;
        
        while(i<a.size() && j<b.size())
        {
            if(a[i]<b[j])
            {
                ans[k++]=a[i];
                i++;
            }
            else
            {
                ans[k++]=b[j++];
            }
        }
        
        while(i<a.size()) ans[k++]=a[i++];
        while(j<b.size()) ans[k++]=b[j++];
        
        return ans;
    }
    
    Node* f(int s,int e,vector<int> &in)
    {
        if(s>=e) return NULL;
        
        int mid=(s+e)/2;
        Node* root=new Node(in[mid]);
        root->left=f(s,mid-1,in);
        root->right=f(mid+1,e,in);
        return root;
    }
    void inorder(Node* root,vector<int>& in)
    {
        if(root==NULL) return;
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> bst1;
        vector<int> bst2;
        
        inorder(root1,bst1);
        inorder(root2,bst2);
        
        return solve(bst1,bst2);
        
       // return f(0,merge.size()-1,merge);
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends