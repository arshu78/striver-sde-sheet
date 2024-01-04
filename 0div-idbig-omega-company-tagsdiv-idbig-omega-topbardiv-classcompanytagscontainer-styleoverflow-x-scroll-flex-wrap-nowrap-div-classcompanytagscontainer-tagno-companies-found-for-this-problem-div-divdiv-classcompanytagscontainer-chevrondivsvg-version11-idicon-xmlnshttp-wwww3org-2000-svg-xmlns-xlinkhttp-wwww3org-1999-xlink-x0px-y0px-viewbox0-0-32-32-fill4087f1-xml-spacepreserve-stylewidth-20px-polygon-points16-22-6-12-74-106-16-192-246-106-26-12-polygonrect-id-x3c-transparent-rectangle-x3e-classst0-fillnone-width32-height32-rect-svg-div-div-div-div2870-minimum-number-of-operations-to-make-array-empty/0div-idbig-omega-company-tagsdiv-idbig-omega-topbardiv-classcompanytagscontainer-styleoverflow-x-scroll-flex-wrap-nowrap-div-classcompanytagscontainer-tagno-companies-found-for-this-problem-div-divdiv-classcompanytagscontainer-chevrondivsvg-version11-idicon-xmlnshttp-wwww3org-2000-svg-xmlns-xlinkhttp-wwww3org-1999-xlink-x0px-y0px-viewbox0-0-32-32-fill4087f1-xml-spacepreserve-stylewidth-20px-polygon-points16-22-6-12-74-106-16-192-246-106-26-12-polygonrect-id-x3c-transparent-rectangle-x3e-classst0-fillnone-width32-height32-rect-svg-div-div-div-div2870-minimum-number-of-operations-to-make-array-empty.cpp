class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        int ans=0;
        for(auto it:mp)
        {
            if(it.second==1) return -1;
             if(it.second % 3 == 1){
                ans += (it.second/3) - 1;
                ans += 2;
            }
            else 
            {
                ans+=it.second/3;
                ans+=(it.second%3)/2;
            }
        }
        return ans;
    }
};