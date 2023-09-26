class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        stack<string> st;
        for(int i=0;i<path.size();i++)
        {
            string temp="";
            if(path[i]=='/') continue;
            
            while(i<path.size() && path[i]!='/')
            {
                temp+=path[i++];
            }
            
            if(temp==".") continue;
            else if(temp=="..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
                
            }
            else st.push(temp);
            
        }
        
        if(st.empty()) return "/";
        while(!st.empty())
        {
            ans="/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};