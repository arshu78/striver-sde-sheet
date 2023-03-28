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
        ListNode* fast=head,*slow=head;
        while(fast->next!=NULL&& fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        
        ListNode *temp=head,*mid=slow->next;
        
         while(mid!=NULL)
        {
            if(temp->val!=mid->val)
            {
                return false;
            }
            temp=temp->next;
            mid=mid->next;
        }
        slow->next=reverseList(slow->next);
        return true;
    }
};