class Solution {
public:
    int f(int keyind,int pos,string &ring,string &key,vector<vector<int>>& v,vector<vector<int>>& dp)
    {
        if(keyind==key.length()) return 0;
        if(dp[keyind][pos]!=-1) return dp[keyind][pos];
        vector<int> p=v[key[keyind]-97];
        int ans=INT_MAX;
        for(int i=0;i<p.size();i++)
        {
            int clock= abs(pos - p[i]);
            int aclock=ring.size() - clock;
            
            int mini=min(clock,aclock);
            
            ans=min(ans,mini + f(keyind+1,p[i],ring,key,v,dp));
        }
        return dp[keyind][pos]= ans + 1;
    }
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> v(26);
        vector<vector<int>> dp(key.size(),vector<int>(ring.size(),-1));
        for(int i=0;i<ring.size();i++)
        {
            v[ring[i] - 97].push_back(i);
        }
        
        return f(0,0,ring,key,v,dp);
    }
};