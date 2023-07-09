//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(head==NULL || head->next==NULL) return head;
        stack<Node*> st;
        
        vector<Node*> a;
        Node* temp=head;
        while(temp!=NULL)
        {
            a.push_back(temp);
            temp=temp->next;
        }
        reverse(a.begin(),a.end());
        
        for(auto it:a)
        {
            if(st.empty())
            {
                st.push(it);
            }
            else if(st.top()->data<=it->data)
            {
                st.push(it);
            }
        }
        head=st.top();
        st.pop();
        temp=head;
        while(!st.empty())
        {
            temp->next=st.top();
            st.pop();
            temp=temp->next;
        }
        
        return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends