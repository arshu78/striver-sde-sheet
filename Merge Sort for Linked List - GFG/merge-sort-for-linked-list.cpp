//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node* l1,Node* l2)
    {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        Node* r=new Node(-1);
        Node* temp=r;
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->data<l2->data)
            {
                temp->next=l1;
                temp=l1;
                l1=l1->next;
            }
            else
            {
                temp->next=l2;
                temp=l2;
                l2=l2->next;
            }
        }
        
        if(l1!=NULL) temp->next=l1;
        if(l2!=NULL) temp->next=l2;
        
        return r->next;
    }
    Node* f(Node* head)
    {
        if(head==NULL || head->next==NULL) return head;
        Node* fast=head->next,*slow=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    Node* mergeSort(Node* head) {
         if(head==NULL || head->next==NULL) return head;
        
        Node* mid=f(head);
        
        Node* left=head;
        Node* right=mid->next;
        mid->next=NULL;
        
        left=mergeSort(left);
        right=mergeSort(right);
        
        Node* res=merge(left,right);
        
        return res;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends