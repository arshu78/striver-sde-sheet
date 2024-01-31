class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
       int n=a.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && a[i]>=a[st.top()])
            {
                st.pop();
            }
            if(!st.empty())
                {ans[i]=st.top() - i;}
            
            st.push(i);
        }
        return ans;
    }
};