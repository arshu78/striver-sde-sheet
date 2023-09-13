class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> mp;
        set<pair<int,int>> st;
        int ans=0;
        for(auto it:nums)
        {
            if(mp.find(it-k)!=mp.end()) 
            {
                st.insert({it,(it-k)});
            }
            if(mp.find(it+k)!=mp.end()) 
            {
                st.insert({it+k,it});
            
            }
            mp[it]++;
        }
        
        return st.size();
    }
};