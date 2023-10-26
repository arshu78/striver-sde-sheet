//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    bool p(int n)
    {
        if(n<2) return false;
       // if(n==2) return true;
        for(int i=2;i<=n/2;i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }
    int check(int a)
    {
        if(p(a)) return a;
        int l=a,n=a;
        for(int i=0;i<=a;i++){
            l=l-1;
            n=n+1;
            if(l>1 && p(l))
            {
                return l;
            }
            if(p(n)) return n;
        }
        return 0;
        
    }
    Node *primeList(Node *head){
        Node* temp=head;
        
        while(temp!=NULL)
        {
            temp->val=check(temp->val);
            temp=temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends