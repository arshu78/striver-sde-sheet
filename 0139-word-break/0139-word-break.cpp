class Solution {
public:
    
    bool f(int i,int n,string& st,set<string>& s,vector<int>& dp)
    {
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        string temp="";
        for(int j=i;j<n;j++)
        {
            temp+=st[j];

            if(s.find(temp)!=s.end())
            {
                if(f(j+1,n,st,s,dp)) return true;
            }
        }

        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<int> dp(s.size()+1,-1);
        for(auto i: wordDict)
        {
            st.insert(i);
        }

        return f(0,s.size(),s,st,dp);
    }
};