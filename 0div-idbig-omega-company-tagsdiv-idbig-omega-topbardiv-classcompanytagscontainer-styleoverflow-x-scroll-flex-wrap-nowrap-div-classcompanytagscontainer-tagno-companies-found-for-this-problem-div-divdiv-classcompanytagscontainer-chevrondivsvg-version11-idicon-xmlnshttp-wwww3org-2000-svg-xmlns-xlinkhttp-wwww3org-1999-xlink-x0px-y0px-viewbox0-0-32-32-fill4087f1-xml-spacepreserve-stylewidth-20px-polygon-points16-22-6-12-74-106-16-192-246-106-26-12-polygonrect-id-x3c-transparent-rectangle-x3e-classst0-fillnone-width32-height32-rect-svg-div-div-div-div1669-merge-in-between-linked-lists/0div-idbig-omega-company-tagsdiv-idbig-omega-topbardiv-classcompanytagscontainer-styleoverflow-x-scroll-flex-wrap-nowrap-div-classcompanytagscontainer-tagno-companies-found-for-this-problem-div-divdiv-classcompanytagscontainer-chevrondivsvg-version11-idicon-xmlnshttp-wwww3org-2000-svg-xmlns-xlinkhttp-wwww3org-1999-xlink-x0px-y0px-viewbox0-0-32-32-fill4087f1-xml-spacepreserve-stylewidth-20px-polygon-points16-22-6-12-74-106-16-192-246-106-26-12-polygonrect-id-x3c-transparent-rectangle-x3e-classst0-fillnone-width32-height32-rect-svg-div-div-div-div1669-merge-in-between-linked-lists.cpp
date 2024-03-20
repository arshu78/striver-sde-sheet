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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        if(list1==NULL || list1->next==NULL)
        {
            return list1;
        }
        
        ListNode* temp=list1;
        ListNode* a_prev;
        ListNode* a_next;
        ListNode* b_prev;
        ListNode* b_next;
        while(a--)
        {
            a_prev=temp;
            temp=temp->next;
        }
        a_next=temp;
        
        temp=list1;
        
         while(b--)
        {
            temp=temp->next;
        }
        
        b_next=temp->next;
        
        temp=list2;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        a_prev->next=list2;
        temp->next=b_next;
        
        return list1;
    }
};