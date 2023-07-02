class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> mp;
        
        int t=0,nt=0;
        
        for(auto it:nums) mp[it]++;
        
        for(auto it:mp)
        {
            t+=it.second/2;
            nt+=it.second%2;
        }
        return {t,nt};
    }
};