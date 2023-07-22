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
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* r=new ListNode(-1);
        ListNode* temp=r;
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val<l2->val)
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
    ListNode* f(ListNode* head)
    {
        if(head==NULL || head->next==NULL) return head;
        ListNode* fast=head->next,*slow=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* mid=f(head);
        
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        
        left=sortList(left);
        right=sortList(right);
        
        ListNode* res=merge(left,right);
        
        return res;
    }
};