class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        string ans="";
        for(auto it:order)
        {
            if(mp.find(it)!=mp.end())
            {
                int cnt=mp[it];
                string a(cnt,it);
                ans+=a;
                mp.erase(it);
            }
        }
        
        for(auto it:mp)
        {
            string a(it.second,it.first);
            ans+=a;
        }
        return ans;
    }
};