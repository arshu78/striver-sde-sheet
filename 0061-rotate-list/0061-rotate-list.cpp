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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        
        int cnt=1;
        ListNode* temp=head;
        
        while(temp->next!=NULL) 
        {
            ++cnt;
            temp=temp->next;
        }
        
        k=k% cnt;
        k=cnt-k;
        temp->next=head;
        while(k--)
        {
            temp=temp->next;
        }
        
        head=temp->next;
        temp->next=NULL;
        
        return head;
    }
};