class Solution {
public:
    bool f(int i,vector<int>& nums,int target)
    {
        if(target==0) return true;
        if(i>=nums.size())
        {
            return target==0;
        }
        
        bool nt=f(i+1,nums,target);
        bool t=false;
        if(target<=nums[i])
        {
            t=f(i+1,nums,target - nums[i]);
        }
        return nt || t;
    }
    bool checkSubarraySum(vector<int>& nums, int k) {
       map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            sum%=k;
            
            if(mp.find(sum)!=mp.end())
            {
                if(i - mp[sum] >1) return true;
            }
            else mp[sum]=i;
        }
        return false;
    }
};