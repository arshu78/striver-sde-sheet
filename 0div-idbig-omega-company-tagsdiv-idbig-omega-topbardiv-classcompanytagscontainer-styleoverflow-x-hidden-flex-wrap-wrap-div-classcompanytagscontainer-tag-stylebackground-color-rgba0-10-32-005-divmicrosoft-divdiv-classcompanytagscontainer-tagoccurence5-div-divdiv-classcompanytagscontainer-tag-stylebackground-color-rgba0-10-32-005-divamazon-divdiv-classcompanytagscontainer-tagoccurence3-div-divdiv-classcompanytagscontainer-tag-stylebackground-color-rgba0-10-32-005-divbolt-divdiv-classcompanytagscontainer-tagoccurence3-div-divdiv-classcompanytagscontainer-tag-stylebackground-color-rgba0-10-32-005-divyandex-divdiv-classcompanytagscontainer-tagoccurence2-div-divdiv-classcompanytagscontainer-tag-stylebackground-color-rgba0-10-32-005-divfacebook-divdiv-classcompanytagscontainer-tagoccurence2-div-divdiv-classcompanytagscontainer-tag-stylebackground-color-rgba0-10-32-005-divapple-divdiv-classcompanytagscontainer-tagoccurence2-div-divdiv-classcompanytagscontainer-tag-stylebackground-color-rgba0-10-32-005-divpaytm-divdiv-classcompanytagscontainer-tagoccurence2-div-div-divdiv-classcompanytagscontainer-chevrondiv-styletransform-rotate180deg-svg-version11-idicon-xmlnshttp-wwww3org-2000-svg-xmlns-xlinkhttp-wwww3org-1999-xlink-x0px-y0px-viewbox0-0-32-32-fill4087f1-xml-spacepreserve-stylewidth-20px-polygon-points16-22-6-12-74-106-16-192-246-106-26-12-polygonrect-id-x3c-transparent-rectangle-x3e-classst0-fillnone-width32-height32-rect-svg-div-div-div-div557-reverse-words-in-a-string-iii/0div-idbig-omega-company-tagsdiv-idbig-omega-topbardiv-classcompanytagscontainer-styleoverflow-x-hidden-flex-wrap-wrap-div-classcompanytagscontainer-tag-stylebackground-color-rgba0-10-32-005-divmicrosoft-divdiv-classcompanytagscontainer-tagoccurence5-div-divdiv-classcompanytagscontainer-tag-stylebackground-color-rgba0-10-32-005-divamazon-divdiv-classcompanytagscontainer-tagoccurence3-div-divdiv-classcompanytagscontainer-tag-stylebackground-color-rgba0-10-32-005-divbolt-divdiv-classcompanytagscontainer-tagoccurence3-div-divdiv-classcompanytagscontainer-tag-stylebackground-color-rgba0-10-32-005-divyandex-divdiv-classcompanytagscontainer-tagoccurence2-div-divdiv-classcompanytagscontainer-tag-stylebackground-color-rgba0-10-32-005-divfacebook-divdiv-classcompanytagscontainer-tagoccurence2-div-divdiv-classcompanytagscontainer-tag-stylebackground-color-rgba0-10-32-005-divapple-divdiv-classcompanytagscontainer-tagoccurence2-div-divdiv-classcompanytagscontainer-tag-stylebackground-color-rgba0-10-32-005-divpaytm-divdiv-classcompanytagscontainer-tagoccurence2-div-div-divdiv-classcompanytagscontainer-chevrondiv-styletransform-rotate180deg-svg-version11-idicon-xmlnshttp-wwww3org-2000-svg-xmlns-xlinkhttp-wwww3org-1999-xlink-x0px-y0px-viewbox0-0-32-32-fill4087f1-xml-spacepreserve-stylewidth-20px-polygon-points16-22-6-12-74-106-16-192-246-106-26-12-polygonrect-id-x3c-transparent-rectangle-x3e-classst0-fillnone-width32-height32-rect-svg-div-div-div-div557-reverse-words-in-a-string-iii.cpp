class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                temp+=s[i];
            }
            else
            {
                //reverse(temp.begin(),temp.end());
                st.push(temp);
                temp="";
            }
            
        }
        st.push(temp);
        
        string ans="";
        while(!st.empty())
        {
            ans+=st.top()+" ";
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};