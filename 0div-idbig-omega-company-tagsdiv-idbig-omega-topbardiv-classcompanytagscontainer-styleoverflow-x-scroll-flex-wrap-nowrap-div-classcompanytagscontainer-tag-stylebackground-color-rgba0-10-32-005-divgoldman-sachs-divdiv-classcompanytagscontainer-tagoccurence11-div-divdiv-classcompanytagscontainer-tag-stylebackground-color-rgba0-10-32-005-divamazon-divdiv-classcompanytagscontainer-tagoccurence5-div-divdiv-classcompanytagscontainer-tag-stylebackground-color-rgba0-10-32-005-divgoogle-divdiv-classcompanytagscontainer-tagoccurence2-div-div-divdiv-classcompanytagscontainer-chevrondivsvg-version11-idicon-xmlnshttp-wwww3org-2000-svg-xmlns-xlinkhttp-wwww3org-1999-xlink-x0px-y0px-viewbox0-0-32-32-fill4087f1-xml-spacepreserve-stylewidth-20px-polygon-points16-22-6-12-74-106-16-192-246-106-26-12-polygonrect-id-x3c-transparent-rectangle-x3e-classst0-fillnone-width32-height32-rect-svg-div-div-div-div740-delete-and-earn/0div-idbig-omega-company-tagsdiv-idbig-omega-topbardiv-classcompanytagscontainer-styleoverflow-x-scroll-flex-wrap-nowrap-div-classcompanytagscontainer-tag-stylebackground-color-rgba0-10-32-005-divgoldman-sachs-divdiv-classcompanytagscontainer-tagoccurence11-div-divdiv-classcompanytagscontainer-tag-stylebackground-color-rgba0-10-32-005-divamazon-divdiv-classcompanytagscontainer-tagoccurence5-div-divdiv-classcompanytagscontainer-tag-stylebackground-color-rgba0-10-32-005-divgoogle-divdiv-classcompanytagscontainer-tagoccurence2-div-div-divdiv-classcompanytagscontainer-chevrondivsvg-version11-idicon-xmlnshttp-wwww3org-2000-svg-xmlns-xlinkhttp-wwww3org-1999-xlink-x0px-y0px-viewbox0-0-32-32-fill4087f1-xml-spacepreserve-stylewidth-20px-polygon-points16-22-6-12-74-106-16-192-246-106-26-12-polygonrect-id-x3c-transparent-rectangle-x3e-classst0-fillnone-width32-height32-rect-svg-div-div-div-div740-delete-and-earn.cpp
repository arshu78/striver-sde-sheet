class Solution {
public:
    int f(int i,vector<int>& nums,vector<int>& dp)
    {
        if(i<0) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int nt= 0 + f(i-1,nums,dp);
        
        int t=0,k=i,sum=0;
        
        while(k>=0 && nums[k]==nums[i])
        {
            sum+=nums[k];
            k--;
        }
        
        while(k>=0 && nums[k]==nums[i]-1)
        {
            k--;
        }
        
        t=sum + f(k,nums,dp);
       
        return dp[i]= max(t,nt);
        
    }
    int deleteAndEarn(vector<int>& nums) {
      sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),-1);
        return f(nums.size()-1,nums,dp);
    }
};