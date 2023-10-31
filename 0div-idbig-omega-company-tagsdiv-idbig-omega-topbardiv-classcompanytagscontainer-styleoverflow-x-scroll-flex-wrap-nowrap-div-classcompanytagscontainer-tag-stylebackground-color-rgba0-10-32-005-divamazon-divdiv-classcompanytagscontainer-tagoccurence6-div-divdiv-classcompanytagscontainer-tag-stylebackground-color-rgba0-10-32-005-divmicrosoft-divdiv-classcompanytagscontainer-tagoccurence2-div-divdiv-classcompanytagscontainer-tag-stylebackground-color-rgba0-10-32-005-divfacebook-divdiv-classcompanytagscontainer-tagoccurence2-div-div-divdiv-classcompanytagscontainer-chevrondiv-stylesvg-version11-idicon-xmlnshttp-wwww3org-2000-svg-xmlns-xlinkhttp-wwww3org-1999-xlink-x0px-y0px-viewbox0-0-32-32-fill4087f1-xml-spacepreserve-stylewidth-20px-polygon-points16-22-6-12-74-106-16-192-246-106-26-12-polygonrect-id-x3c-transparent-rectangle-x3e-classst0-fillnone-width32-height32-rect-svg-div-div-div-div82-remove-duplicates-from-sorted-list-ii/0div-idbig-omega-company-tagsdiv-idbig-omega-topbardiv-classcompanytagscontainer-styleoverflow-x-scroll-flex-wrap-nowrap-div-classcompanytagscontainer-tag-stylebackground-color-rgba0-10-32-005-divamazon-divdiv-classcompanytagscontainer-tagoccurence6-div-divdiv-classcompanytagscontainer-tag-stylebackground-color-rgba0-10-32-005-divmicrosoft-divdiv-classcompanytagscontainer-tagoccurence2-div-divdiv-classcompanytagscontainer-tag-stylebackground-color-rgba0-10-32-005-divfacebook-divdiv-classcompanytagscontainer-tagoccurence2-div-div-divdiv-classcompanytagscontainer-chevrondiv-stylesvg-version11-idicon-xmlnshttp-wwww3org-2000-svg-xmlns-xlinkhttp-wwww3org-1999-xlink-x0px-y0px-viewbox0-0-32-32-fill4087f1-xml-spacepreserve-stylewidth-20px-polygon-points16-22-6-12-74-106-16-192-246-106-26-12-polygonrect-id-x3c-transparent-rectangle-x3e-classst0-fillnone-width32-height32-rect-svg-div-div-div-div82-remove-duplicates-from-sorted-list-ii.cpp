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
    ListNode* deleteDuplicates(ListNode* head) {
       unordered_map<int,int> mp;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            mp[temp->val]++;
            temp=temp->next;
        }
        ListNode* d=new ListNode(-1);
        ListNode* cur=d;
        temp=head;
        
        while(temp!=NULL)
        {
            if(mp[temp->val]<=1) 
            {
                ListNode* node=new ListNode(temp->val);
                cur->next=node;
                cur=cur->next;
            }
            temp=temp->next;
        }
        return d->next;
    }
};