class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        int m=0;
        for(auto it:nums)
        {
            mp[it]++;
            m=max(m,mp[it]);
        }
        int sum=0;
        for(auto it:mp)
        {
            if(it.second==m) sum+=m;
        }
        return sum;
    }
};