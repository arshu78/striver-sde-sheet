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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* cur,*prev=dummy,*nex;
        cur=head;
        int len=0;
        while(cur!=NULL) 
        {
            len++;
            cur=cur->next;
        }
        while(len>=k)
        {
            cur=prev->next;
            nex=cur->next;
            for(int i=0;i<k-1;i++)
            {
                cur->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=cur->next;
                
            }
            prev=cur;
            len-=k;
        }
        return dummy->next;
    }
};