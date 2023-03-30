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
private:
    ListNode* reverseList(ListNode* head)
    {
        if(head==NULL || head->next==NULL) return head;
        ListNode* n=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return n;
        
    }
public:
    bool isPalindrome(ListNode* head) {
         if(head==NULL||head->next==NULL) return true;
      ListNode* fast=head,*slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* mid=slow;
        
        slow->next=reverseList(slow->next);
        slow=slow->next;
        fast=head;
        while(slow!=NULL)
        {
            if(fast->val!=slow->val) return false;
            
            slow=slow->next;
            fast=fast->next;
        }
        mid->next=reverseList(mid->next);
        return true;
        
    }
};