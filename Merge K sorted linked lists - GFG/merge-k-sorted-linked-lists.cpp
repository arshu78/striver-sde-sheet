//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

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

class Solution{
  public:
    Node* mergetwo(Node* n1,Node* n2)
    {
        if(n1==NULL) return n2;
        if(n2==NULL) return n1;
        
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        
        while(n1!=NULL && n2!=NULL)
        {
            if(n1->data<n2->data)
            {
                temp->next=n1;
                temp=temp->next;
                n1=n1->next;
            }
            else
            {
                temp->next=n2;
                temp=temp->next;
                n2=n2->next;
            }
        }
        
        while(n1!=NULL)
        {
            temp->next=n1;
                temp=temp->next;
                n1=n1->next;
        }
        
        while(n2!=NULL)
        {
            temp->next=n2;
                temp=temp->next;
                n2=n2->next;
        }
        
        return dummy->next;
    }
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        
          priority_queue<Node*> pq;
          for(int i=0;i<K;i++)
          {
              pq.push(arr[i]);
          }
          while(pq.size()>1)
          {
              Node* n1=pq.top();
              pq.pop();
              Node* n2=pq.top();
              pq.pop();
              
              pq.push(mergetwo(n1,n2));
              
          }
          return pq.top();
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends