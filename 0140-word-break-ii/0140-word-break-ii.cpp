class Solution {
public:
    void f(int i,string s,set<string>& st,string temp,vector<string>& ans)
    {
        if(i==s.length())
        {
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        string str="";
        for(int ind=i;ind<s.length();ind++)
        {
            str+=s[ind];
            if(st.find(str)!=st.end())
            {
                str+=' ';
                f(ind+1,s,st,temp+str,ans);
                str.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto it:wordDict)
        {
            st.insert(it);
        }
        string temp="";
        vector<string> ans;
        f(0,s,st,temp,ans);
        
        return ans;
    }
};