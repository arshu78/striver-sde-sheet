class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        for(auto it:matches)
        {
            if(mp.find(it[0])==mp.end() || mp[it[0]]==0)
            {
                mp[it[0]]=0;
            }
            mp[it[1]]++;
        }
        vector<int> a,b;
        for(auto it:mp)
        {
            if(it.second==0) a.push_back(it.first);
            else if(it.second==1) b.push_back(it.first);
        }
        return {a,b};
    }
};