class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        for(auto it:s)
        {
            if(!st.empty() && abs(st.top() - it)==32)
            {
                st.pop();                
            }
            else st.push(it);
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};