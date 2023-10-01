class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp;
        string ans="";
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                temp+=s[i];
            }
            else
            {
                //reverse(temp.begin(),temp.end());
              //  st.push(temp);
                ans =temp + " "+ ans;
                temp="";
            }
            
        }
        ans =temp + " "+ ans;
        //st.push(temp);
        
        
        // while(!st.empty())
        // {
        //     ans+=st.top()+" ";
        //     st.pop();
        // }
        ans.pop_back();
        return ans;
    }
};