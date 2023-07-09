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
    vector<int> ngs(vector<int> a,int n)
    {
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=a[i]) st.pop();
            
            if(!st.empty()) ans[i]=st.top();
            
            st.push(a[i]);
        }
        
        return ans;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* temp=head;
        
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        
        
        return ngs(ans,ans.size());
    }
};