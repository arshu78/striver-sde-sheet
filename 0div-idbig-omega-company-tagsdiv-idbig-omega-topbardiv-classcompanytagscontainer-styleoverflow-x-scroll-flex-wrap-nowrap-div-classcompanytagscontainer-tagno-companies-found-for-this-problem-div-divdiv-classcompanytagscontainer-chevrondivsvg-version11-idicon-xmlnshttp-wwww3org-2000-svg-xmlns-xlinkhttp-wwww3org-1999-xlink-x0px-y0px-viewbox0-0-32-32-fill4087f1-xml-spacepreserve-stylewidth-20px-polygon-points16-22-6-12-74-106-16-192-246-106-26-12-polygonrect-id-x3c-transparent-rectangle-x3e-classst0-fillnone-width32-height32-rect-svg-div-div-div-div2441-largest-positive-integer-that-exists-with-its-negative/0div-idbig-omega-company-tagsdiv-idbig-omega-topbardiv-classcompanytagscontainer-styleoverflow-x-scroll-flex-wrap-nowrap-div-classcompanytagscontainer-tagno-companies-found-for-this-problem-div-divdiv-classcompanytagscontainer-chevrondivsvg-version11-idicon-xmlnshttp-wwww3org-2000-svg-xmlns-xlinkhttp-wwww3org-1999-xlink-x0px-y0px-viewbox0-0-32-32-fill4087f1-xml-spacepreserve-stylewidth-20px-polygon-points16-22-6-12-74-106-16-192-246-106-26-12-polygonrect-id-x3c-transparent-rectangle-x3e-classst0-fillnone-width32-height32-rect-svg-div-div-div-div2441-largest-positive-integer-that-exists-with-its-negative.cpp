class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans=-1;
        map<int,int> mp;
        for(auto it:nums)
        {
            if(it>0 && mp.find(-it)!=mp.end())
                ans=max(ans,it);
            else if(it<0 && mp.find(abs(it))!=mp.end())
            {
                int p=abs(it);
                ans=max(ans,p);
            }
            else mp[it]++;
        }
        return ans;
    }
};