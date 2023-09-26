class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int> mp;
        unordered_map<char,bool> vis;
        for(auto it:s) 
        {
            mp[it]++;
            vis[it]=false;
        }
        string ans="";
        for(auto it:s)
        {
            mp[it]--;
            if(vis[it]) continue;
            while(!ans.empty() && ans.back() > it && mp[ans.back()]>0)
            {
                vis[ans.back()]=false;
                ans.pop_back();
            }
            
            vis[it]=true;
            ans+=it;
        }
        return ans;
    }
};