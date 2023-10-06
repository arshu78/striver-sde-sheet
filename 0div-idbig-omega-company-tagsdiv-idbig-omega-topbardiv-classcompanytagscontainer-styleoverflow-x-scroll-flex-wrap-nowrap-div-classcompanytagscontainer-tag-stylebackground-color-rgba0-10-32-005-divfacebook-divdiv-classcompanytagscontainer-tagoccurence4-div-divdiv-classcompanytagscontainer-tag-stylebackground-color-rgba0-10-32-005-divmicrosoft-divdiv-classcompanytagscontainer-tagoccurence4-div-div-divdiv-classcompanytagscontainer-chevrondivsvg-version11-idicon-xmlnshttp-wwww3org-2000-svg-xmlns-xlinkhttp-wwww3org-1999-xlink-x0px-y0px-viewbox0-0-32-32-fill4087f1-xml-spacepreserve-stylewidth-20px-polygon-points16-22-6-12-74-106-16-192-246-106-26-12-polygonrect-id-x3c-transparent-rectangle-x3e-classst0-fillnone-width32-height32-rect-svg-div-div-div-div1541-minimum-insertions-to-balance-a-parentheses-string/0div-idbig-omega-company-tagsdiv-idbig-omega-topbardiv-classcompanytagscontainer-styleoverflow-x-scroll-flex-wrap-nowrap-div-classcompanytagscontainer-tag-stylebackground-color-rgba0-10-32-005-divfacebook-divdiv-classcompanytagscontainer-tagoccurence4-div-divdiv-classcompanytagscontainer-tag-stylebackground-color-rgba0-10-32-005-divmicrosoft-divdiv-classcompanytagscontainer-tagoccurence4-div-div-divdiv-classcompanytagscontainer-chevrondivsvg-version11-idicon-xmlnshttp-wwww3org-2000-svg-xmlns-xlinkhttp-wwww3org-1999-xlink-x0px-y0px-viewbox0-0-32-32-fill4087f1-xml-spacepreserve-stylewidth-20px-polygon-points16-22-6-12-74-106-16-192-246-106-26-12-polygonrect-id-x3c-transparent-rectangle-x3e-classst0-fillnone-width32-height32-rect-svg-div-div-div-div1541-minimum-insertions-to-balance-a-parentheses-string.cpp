class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int ans=0;
        for(int i=0;i<s.size();)
        {
            if(s[i]=='(')
            {
                st.push('(');
                i++;
            }
            else
            {
                if(st.empty())
                {
                    if(i+1<s.size() && s[i+1]==')')
                    {
                        ans++;
                        i+=2;
                    }
                    else
                    {
                        ans+=2;
                        i++;
                    }
                }
                else
                {
                    if(i+1<s.size() && s[i+1]==')')
                    {
                        i+=2;
                    }
                    else
                    {
                        ans++;
                        i++;
                    }
                    st.pop();
                }
            }
        }
        
        return st.size()*2 + ans;
    }
};