/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp=head,*front=head;
        
        //creating copies node
        
        while(temp!=NULL)
        {
            front=temp->next;
            Node* copy=new Node(temp->val);
            temp->next=copy;
            copy->next=front;
            temp=front;
        }
        
        //assigning random pointers
        
        temp=head;
        while(temp!=NULL)
        {
             if(temp->random!=NULL)
             {
                 temp->next->random=temp->random->next;
             }
            
            temp=temp->next->next;
        }
        
        //rearrange original list
        
        Node* dummy= new Node(-1);
        Node* copy=dummy;
        temp=head;
        while(temp!=NULL)
        {
            front=temp->next->next;
            copy->next=temp->next;
            temp->next=front;
            copy=copy->next;
            temp=front;
        }
        
        return dummy->next;
    }
};