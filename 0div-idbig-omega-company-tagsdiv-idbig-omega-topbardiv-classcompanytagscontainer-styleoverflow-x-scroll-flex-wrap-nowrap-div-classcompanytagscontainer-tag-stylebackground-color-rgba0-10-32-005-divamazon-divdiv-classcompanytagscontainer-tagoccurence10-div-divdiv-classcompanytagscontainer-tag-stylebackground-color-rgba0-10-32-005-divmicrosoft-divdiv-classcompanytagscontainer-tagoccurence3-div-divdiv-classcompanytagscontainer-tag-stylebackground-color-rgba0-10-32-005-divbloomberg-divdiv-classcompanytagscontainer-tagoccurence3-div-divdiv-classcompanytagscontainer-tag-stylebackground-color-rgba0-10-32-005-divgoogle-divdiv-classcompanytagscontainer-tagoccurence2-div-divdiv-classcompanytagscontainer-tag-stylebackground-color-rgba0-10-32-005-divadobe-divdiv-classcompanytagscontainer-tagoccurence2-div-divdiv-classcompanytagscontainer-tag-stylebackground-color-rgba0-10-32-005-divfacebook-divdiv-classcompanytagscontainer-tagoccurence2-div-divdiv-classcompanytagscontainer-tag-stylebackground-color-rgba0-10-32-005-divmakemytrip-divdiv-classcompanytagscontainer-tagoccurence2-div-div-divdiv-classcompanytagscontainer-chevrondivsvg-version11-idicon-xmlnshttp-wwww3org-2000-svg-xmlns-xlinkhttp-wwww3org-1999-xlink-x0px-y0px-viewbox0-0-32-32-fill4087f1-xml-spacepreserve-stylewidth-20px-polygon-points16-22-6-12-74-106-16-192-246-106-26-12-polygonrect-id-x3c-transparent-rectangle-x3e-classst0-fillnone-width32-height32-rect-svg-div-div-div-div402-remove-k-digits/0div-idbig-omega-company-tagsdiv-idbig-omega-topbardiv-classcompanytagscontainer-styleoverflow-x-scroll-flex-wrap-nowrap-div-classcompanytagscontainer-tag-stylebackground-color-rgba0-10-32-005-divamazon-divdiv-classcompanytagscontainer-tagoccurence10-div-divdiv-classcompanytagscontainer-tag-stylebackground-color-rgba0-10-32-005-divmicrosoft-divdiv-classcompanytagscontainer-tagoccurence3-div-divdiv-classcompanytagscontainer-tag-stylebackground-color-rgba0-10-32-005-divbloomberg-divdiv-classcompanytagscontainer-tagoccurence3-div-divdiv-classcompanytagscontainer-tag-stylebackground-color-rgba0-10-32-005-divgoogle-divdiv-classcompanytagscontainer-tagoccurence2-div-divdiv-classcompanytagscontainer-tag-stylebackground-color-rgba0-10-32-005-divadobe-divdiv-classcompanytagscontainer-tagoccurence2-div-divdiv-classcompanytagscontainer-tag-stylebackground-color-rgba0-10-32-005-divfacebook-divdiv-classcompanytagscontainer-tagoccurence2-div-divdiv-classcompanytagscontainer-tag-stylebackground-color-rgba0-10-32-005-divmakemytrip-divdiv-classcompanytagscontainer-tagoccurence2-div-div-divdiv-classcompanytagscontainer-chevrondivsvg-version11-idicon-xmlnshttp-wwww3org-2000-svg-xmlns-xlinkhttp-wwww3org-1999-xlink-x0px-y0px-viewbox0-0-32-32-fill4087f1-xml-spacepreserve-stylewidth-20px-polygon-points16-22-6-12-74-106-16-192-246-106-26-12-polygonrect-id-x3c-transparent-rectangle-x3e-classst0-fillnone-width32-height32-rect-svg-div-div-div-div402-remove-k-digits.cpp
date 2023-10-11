class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto it:num)
        {
            while(!st.empty() && (st.top()-'0') > (it-'0') && k>0)
            {
                st.pop();
                k--;
            }
            st.push(it);
        }
        
        while(!st.empty() && k--)
        {
            st.pop();
        }
        string ans="";
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
    //    cout<<ans<<" ";
        int i=0;
        while(ans[i]=='0' && i<ans.size())
        {
            i++;
        }
        
       // if(i==ans.size()) return "0";
        ans= ans.substr(i);
        if(ans=="") return "0";
        
        return ans;
    }
};