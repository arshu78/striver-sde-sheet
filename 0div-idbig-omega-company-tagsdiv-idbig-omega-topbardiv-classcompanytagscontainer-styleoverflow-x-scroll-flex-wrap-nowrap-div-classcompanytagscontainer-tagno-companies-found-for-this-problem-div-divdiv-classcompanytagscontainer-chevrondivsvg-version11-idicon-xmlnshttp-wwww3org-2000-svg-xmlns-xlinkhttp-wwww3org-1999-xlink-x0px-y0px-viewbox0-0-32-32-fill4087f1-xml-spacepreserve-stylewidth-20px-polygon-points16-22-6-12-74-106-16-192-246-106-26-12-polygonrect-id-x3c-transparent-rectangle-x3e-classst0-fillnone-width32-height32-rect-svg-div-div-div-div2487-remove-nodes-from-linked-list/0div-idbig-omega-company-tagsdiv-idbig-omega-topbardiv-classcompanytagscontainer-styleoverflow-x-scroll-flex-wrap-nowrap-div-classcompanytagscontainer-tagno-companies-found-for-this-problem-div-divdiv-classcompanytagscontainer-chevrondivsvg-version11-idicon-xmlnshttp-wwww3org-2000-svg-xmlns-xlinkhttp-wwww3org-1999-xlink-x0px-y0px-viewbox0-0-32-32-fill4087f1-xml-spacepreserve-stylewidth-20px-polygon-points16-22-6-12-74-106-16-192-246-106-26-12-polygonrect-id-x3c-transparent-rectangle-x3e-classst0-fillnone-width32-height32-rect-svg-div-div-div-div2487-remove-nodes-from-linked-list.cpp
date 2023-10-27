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
    ListNode* removeNodes(ListNode* head) {
        vector<int> a,b;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            a.push_back(temp->val);
            temp=temp->next;
        }
        int n=a.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=a[i])
            {
                st.pop();
            }
            if(st.empty()) b.push_back(a[i]);
            
            st.push(a[i]);
        }
        ListNode *dummy=new ListNode(-1);
        temp=dummy;
        for(int i=b.size()-1;i>=0;i--)
        {
            ListNode* node=new ListNode(b[i]);
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }
};