/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        
        len=len-n;
        if(len==0)
        {
           
            head=head->next;
            return head;
           
        }
        temp=head;
        for(int i=0;i<len-1;i++)
        {
            temp=temp->next;
            
        }
        
      //  ListNode* del=temp->next;
        if(temp->next!=NULL)
        {
            temp->next=temp->next->next;
        }
        else
        {
            temp->next=NULL;
        }
      //  delete del;
        return head;
    }
};