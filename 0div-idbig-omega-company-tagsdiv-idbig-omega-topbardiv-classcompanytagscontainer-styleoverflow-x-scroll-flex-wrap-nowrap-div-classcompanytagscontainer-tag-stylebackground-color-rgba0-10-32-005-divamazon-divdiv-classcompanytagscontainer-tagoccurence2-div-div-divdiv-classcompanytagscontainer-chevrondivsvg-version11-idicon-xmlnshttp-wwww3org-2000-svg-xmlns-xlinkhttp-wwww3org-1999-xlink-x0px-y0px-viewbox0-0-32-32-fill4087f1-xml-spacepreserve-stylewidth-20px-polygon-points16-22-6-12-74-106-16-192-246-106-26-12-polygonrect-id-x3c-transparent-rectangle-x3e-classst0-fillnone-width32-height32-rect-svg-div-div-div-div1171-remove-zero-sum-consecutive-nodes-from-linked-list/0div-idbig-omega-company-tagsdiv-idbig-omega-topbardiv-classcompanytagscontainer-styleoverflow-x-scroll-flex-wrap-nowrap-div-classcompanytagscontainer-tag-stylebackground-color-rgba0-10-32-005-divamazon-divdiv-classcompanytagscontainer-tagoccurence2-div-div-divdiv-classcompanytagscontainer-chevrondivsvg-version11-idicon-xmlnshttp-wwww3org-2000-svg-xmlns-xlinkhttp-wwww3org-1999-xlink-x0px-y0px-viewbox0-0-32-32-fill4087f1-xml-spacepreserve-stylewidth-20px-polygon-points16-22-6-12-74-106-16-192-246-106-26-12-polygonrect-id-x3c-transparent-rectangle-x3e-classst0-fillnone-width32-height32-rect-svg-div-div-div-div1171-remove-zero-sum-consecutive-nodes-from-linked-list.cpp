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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* d=new ListNode(-1);
        ListNode* temp=d;
        d->next=head;
        int sum=0;
        unordered_map<int,ListNode*> mp;
        while(temp!=NULL)
        {
            sum+=temp->val;
            
            if(mp.count(sum))
            {
                
                temp=mp[sum]->next;
                int p=sum + temp->val;
                while(p!=sum)
                {
                    mp.erase(p);
                    temp=temp->next;
                    p+=temp->val;
                }
                
                mp[sum]->next=temp->next;
                
            }
            else
            {
                mp[sum]=temp;
            }
            temp=temp->next;
        }
        return d->next;
    }
};