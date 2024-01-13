class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp;
        for(auto it:s) mp[it]++;
        
        int cnt=0;
        
        for(auto it:t)
        {
            if(mp.find(it)!=mp.end())
            {
                cnt++;
                mp[it]--;
                if(mp[it]==0) mp.erase(it);
            }
        }
        return s.size() - cnt;
    }
};