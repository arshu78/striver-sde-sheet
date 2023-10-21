class Solution {
public:
    bool check(string &s,string &p,unordered_map<char,int> mp)
    {
       int i=0;
        
        for(auto it:s)
        {
            if(it==p[i] && mp.find(p[i])!=mp.end())
            {
                mp[p[i]]--;
                if(mp[p[i]]==0) mp.erase(p[i]);
                i++;
            }
            else if(isupper(it)) return false;
           
        }
        return i==p.size();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        unordered_map<char,int> mp;
        vector<bool> ans;
        for(auto it:pattern)
        {
            mp[it]++;
        }
        
        for(auto it:queries)
        {
            if(check(it,pattern,mp)) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};