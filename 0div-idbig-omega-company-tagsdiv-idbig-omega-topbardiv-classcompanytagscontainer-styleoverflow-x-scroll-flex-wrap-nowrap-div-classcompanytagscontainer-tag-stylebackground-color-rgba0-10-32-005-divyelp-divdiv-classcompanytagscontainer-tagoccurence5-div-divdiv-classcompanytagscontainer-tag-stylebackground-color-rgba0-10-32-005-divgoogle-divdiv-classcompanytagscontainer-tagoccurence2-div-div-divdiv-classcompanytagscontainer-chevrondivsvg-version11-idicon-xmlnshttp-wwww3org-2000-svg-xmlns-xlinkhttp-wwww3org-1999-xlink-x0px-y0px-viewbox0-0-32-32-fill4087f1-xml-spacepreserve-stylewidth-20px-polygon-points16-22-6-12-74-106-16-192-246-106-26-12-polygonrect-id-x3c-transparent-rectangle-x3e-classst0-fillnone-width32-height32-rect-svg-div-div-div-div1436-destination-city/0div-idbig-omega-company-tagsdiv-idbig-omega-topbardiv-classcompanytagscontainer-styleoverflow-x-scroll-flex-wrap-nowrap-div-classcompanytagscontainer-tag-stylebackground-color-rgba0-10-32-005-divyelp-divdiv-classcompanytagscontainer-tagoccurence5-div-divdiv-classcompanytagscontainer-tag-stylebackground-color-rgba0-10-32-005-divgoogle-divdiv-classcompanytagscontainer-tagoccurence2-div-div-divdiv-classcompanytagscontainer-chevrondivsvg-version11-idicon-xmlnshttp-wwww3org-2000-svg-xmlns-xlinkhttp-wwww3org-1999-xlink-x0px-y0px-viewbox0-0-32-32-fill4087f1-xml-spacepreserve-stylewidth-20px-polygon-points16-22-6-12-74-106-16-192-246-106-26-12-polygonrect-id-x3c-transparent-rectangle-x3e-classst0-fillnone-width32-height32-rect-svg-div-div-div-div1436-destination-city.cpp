class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,string> mp;
        for(auto it:paths)
        {
            mp[it[0]]=it[1];
        }
        
        string ans="",t=paths[0][0];
        while(mp.find(t)!=mp.end())
        {
            ans=mp[t];
            t=mp[t];
        }
        return ans;
    }
};