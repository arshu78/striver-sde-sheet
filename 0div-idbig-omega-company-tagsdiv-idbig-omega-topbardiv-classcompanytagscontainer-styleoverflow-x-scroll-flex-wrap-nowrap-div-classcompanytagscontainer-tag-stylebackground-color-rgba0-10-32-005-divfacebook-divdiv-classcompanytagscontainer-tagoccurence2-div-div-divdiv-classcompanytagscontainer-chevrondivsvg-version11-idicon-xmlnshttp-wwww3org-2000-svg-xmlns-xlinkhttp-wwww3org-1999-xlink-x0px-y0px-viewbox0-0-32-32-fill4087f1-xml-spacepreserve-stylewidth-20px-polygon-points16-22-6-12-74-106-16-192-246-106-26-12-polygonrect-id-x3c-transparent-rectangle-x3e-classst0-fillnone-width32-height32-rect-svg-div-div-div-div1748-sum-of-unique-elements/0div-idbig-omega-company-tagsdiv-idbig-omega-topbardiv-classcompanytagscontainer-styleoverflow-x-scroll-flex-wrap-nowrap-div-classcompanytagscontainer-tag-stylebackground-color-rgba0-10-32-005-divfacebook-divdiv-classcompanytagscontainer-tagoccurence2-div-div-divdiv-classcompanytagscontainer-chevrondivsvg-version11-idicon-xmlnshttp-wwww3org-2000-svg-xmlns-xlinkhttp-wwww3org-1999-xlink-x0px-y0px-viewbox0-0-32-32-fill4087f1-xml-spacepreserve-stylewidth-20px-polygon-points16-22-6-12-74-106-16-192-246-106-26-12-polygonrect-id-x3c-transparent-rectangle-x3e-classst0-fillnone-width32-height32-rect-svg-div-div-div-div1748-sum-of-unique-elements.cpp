class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto i:nums) mp[i]++;
        
        for(auto it:mp) if(it.second==1) ans+=it.first;
        
        return ans;
    }
};