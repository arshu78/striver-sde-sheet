class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it:s) mp[it]++;
        int c=0;
        for(auto it:t)
        {
            if(mp.find(it)!=mp.end() and mp[it]>0)
            {
                c++;
                mp[it]--;
               // if(mp[it]==0) mp.erase(it);
            }
         
        }
        return s.size() - c;
    }
};