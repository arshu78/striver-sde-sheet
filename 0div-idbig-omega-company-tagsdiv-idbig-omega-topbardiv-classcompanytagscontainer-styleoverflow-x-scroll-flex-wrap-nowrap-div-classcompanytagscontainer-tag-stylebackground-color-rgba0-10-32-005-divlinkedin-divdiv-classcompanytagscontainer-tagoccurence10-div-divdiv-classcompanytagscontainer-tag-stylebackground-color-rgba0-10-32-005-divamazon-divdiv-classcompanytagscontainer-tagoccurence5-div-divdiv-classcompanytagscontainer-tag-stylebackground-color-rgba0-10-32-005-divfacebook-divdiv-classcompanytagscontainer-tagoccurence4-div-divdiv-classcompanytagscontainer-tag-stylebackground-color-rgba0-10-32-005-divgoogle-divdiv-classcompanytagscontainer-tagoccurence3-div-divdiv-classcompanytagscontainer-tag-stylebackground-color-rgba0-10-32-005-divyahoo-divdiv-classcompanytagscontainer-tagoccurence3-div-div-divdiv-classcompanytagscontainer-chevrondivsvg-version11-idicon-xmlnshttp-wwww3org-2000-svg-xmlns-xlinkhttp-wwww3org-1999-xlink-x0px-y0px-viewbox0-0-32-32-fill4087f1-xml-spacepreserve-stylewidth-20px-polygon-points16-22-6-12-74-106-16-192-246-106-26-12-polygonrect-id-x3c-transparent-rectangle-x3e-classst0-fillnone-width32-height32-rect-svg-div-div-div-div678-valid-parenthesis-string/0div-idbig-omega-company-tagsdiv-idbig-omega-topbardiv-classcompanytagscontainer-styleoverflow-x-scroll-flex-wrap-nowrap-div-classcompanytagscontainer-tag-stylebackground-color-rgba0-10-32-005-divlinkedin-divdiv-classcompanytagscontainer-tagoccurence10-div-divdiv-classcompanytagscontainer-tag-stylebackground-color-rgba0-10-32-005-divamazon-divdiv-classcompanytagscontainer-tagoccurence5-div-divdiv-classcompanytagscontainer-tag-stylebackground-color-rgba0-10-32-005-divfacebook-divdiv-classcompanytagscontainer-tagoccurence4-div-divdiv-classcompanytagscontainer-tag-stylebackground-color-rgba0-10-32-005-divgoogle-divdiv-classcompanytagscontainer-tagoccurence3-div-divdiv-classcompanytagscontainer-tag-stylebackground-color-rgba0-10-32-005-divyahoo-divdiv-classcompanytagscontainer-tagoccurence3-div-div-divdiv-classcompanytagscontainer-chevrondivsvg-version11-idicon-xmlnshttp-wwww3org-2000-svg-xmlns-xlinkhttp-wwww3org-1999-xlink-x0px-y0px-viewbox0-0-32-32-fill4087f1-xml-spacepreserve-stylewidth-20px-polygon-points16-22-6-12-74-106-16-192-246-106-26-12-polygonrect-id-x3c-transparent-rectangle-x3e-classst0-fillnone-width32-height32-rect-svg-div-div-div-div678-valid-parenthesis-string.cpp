class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st1,st2;
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='(')
            {
                st1.push(i);
            }
            else if(s[i]==')')
            {
                if(!st1.empty())
                {
                    st1.pop();
                }
                else if(!st2.empty())
                {
                    st2.pop();
                }
                else
                {
                    return false;
                }
            }
            else st2.push(i);
            
            i++;
        }
        
        if(st1.empty()) return true;
        else 
        {
            while(!st1.empty() && !st2.empty())
            {
                if(st1.top()<st2.top())
                {
                    st1.pop();
                    st2.pop();
                }
                else return false;
            }
            
        }
        return st1.empty();
    }
};