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
    ListNode* partition(ListNode* head, int x) {
        ListNode* firstpart=new ListNode(-1);
        ListNode* secondpart=new ListNode(-1);
        ListNode* temp=head,*tail2=secondpart,*tail1=firstpart;
        
        while(temp!=NULL)
        {
            if(temp->val>=x)
            {
                ListNode* n=new ListNode(temp->val);
                tail2->next=n;
                tail2=tail2->next;
            }
            else
            {
                ListNode* n=new ListNode(temp->val);
                tail1->next=n;
                tail1=tail1->next;
            }
            temp=temp->next;
        }
       
        tail1->next=secondpart->next;
        
        return firstpart->next;
    }
};