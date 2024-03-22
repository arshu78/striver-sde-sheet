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
    ListNode* rev(ListNode* head)
    {
        if(head==NULL) return NULL;
        ListNode* cur=head,*pre=NULL,*nex=NULL;

        while(cur!=NULL)
        {
            nex=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nex;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head,*slow=head;

        while(fast->next!=NULL && fast->next->next!=NULL) 
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=rev(slow->next);
        fast=head;

        while(mid!=NULL)
        {
            if(fast->val!=mid->val) return false;
            mid=mid->next;
            fast=fast->next;
        }

        return true;


    }
};