class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans="";
        stack<pair<char,int>> st;
        for(auto it: s)
        {
            if(st.empty())
            {
                st.push({it,1});
                continue;
            }
            
            char c=st.top().first;
            int cnt=st.top().second;
            
            if(c==it)
            {
                st.pop();
                st.push({it,cnt+1});
            }
            else
            {
                st.push({it,1});
            }
            while(!st.empty() && st.top().second==k) st.pop();
            
        }
        
        
        while(!st.empty())
        {
           int cnt=st.top().second;
            char c=st.top().first;
            st.pop();
            while(cnt--)
            {
                ans+=c;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};