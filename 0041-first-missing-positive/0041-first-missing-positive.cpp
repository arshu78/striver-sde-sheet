class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        
        int ans=-1;
        for(int i=1;i<=nums.size();i++)
        {
            if(mp.find(i)==mp.end())
            {
                ans=i;
                break;
            }
        }
        
        if(ans==-1) return nums.size()+1;
        
        return ans;
    }
};