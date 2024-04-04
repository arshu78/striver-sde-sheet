class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans=0;
        for(auto it:s)
        {
            if(!st.empty() && it==')' && st.top()=='(')
            {
                st.pop();
            }
            else if(it=='(') st.push(it);
            
            int size=st.size();
            ans=max(ans,size);
        }
        return ans;
    }
};