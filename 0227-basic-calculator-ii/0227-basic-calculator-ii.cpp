class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        char op='+';
        int cur=0;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                cur=cur * 10 + (s[i]-'0');
            }
            if(!isdigit(s[i]) && s[i]!=' ' || i==n-1)
            {
                if(op=='+')
                {
                    st.push(cur);
                }
                else if(op=='-')
                {
                    st.push(-cur);
                }
                else if(op=='*')
                {
                    int t=st.top();
                    st.pop();
                    st.push(t * cur);
                }
                else if(op=='/')
                {
                    int t=st.top();
                    st.pop();
                    st.push(t / cur);
                }
                op=s[i];
                cur=0;
            }
        }
        
        int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};