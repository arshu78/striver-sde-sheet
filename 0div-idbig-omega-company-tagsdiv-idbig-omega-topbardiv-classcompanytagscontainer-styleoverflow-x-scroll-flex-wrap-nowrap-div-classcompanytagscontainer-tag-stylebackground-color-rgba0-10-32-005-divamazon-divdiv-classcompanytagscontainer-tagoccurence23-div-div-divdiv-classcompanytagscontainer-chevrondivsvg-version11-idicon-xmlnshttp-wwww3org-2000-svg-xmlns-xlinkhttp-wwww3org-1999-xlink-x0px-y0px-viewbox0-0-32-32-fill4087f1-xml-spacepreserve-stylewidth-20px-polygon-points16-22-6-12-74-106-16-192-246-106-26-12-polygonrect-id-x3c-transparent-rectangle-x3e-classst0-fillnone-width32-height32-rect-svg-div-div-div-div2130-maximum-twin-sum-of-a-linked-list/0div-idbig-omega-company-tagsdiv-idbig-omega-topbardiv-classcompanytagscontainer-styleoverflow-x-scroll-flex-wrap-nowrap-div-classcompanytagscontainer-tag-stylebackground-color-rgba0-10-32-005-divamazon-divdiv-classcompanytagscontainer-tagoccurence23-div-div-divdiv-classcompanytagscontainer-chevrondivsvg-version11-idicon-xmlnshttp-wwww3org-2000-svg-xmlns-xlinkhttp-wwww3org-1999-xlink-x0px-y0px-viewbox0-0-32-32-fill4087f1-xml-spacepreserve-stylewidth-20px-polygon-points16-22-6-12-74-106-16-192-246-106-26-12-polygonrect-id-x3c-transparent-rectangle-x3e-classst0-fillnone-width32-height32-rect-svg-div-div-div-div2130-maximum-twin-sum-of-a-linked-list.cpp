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
    ListNode* f(ListNode* head)
    {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* cur=head,*prev=NULL,*nex=head->next;
        
        while(cur!=NULL)
        {
          //  cout<<cur->val<<" ";
            cur->next=prev;
            prev=cur;
            cur=nex;
            if(nex!=NULL) nex=nex->next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
       
      
        ListNode* f1=head,*s1=head;
        int maxi=0;
        while(f1!=NULL && f1->next!=NULL)
        {
             s1=s1->next;
            f1=f1->next->next;
        }
        
         ListNode* rev=f(s1);
        while(rev && head)
        {
            maxi=max(maxi,rev->val + head->val);
            rev=rev->next;
            head=head->next;
        }
        return maxi;
    }
};