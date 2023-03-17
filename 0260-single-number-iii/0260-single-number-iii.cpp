class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        for(auto it:nums) mp[it]++;
        
        for(auto it:nums) if(mp[it]==1) ans.push_back(it);
        return ans;
    }
};