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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* a=head;
        int p=0;
        while(a!=NULL)
        {
            p+=a->val;
            if(a!=head && a->val==0)
            {
                ListNode* node=new ListNode(p);
                temp->next=node;
                temp=temp->next;
                p=0;
                
            }
            a=a->next;
        }
        return dummy->next;
    }
};