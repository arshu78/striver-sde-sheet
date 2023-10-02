class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sign =1;
        int sum=0;
        
        for(int i=0;i<s.size();i++)
        {
            int num=0;
            if(s[i]>='0' && s[i]<='9')
            {
                while(s.size()>i && s[i]>='0' && s[i]<='9')
                {
                    num= num * 10 + (s[i] - '0');
                    i++;
                }
                
                sum+=num * sign;
                i--;
            }
            else if(s[i]=='(')
            {
                st.push(sum);
                st.push(sign);
                sum=0;
                sign=1;
            }
            else if(s[i]=='+')
            {
                sign=1;
            }
            else if(s[i]=='-')
            {
                sign=-1;
            }
            else if(s[i]==')')
            {
                sum*=st.top();
                st.pop();
                sum+=st.top();
                st.pop();
            }
        }
        return sum;
    }
};