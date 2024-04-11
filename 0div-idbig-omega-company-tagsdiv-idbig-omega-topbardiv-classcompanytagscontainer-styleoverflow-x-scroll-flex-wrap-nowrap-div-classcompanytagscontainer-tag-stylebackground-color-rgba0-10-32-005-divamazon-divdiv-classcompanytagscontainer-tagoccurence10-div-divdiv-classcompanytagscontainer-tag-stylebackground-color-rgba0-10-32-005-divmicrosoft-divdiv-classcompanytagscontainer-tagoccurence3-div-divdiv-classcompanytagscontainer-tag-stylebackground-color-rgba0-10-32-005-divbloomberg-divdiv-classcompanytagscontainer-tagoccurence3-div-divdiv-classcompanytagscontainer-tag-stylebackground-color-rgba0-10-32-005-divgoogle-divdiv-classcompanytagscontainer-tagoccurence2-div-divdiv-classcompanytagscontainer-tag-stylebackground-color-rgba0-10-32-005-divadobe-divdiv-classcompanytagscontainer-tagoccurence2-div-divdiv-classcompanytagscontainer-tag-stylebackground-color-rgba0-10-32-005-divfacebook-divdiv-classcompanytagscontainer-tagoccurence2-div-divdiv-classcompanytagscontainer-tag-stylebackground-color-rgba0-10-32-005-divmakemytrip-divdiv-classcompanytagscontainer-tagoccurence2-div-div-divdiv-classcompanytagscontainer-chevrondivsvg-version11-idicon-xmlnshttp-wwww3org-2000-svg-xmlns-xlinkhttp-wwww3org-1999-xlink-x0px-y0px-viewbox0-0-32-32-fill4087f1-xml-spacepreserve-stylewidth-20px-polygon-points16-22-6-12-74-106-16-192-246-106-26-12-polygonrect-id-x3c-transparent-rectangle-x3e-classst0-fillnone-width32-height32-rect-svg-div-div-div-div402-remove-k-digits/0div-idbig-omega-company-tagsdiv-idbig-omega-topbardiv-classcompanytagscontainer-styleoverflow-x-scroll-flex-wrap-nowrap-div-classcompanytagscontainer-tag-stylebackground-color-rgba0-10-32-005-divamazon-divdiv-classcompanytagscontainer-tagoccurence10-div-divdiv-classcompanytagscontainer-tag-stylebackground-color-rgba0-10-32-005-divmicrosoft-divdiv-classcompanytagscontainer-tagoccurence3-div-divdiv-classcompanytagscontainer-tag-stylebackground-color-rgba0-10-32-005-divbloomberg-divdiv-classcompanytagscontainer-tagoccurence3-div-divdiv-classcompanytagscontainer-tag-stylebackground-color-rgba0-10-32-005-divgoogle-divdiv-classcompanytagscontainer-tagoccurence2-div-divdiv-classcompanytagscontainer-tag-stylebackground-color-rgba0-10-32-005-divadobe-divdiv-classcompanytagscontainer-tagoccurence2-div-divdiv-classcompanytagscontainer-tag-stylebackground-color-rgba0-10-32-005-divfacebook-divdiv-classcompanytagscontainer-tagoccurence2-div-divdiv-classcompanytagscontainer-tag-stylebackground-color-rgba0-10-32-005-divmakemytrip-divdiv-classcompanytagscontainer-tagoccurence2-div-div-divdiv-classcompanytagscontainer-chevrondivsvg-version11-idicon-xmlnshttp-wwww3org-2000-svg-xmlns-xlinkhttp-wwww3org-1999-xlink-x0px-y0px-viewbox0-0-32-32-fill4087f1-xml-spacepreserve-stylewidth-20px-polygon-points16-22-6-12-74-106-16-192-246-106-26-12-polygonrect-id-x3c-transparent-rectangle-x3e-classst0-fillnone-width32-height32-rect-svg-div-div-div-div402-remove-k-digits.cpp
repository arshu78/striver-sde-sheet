class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()<=k) return "0";
        stack<char> st;
        
        for(auto it:num)
        {
            while(!st.empty() && (st.top() - '0') > it - '0' && k>0)
            {
                st.pop();
                k--;
            }
            
            st.push(it);
        }
        
        while(!st.empty() && k>0)
        {
            st.pop();
            k--;
        }
        
        string ans="";
         while(!st.empty())
         {
             ans+=st.top();
             st.pop();
         }
        
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='0')
        {
            i++;
        }
        ans=ans.substr(i);
        if(ans=="") return "0";
        
        return ans;
        
    }
};