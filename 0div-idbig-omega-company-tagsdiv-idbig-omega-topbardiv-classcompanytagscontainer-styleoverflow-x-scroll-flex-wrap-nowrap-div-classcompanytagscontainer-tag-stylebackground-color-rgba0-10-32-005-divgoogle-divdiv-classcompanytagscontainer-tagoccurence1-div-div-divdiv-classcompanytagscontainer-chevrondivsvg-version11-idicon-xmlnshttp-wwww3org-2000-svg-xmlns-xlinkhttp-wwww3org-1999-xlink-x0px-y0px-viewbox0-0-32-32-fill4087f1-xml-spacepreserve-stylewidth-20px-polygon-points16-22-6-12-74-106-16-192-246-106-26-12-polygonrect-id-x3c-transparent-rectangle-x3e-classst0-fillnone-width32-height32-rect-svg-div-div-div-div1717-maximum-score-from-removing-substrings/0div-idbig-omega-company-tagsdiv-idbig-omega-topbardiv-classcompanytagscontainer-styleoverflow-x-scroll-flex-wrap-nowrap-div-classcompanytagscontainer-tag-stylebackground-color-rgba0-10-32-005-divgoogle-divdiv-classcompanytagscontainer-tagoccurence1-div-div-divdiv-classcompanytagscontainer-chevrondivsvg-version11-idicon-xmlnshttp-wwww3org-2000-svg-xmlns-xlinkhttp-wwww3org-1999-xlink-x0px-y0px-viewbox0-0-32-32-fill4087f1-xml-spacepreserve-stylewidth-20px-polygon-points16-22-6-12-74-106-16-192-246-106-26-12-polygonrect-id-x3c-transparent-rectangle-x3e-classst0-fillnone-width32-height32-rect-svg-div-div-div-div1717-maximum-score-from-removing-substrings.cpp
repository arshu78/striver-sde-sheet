class Solution {
public:
    int f(string &s,char a,char b)
    {
        stack<char> st;
        int cnt=0;
        for(auto it:s)
        {
            if(!st.empty() && st.top()==a && it==b)
            {
                cnt++;
                st.pop();
            }
            else st.push(it);
        }
        
        s="";
        while(!st.empty())
        {
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        
        return cnt;
    }
    int maximumGain(string s, int x, int y) {
        int xa=0,xb=0;
        if(x>y)
        {
            xa= f(s,'a','b');
            xb= f(s, 'b','a');
        }
        else
        {
            xb= f(s, 'b', 'a');
            xa= f(s, 'a', 'b');
        }
        
        return xa* x + xb* y;
    }
};