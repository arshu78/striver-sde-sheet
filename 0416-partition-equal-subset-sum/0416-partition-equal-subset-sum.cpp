class Solution {
public:
    bool f(int i,int target,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(target==0) return true;
        if(i==0)
        {
            return nums[0]==target;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        bool np=f(i-1,target,nums,dp);
        bool p=false;
        if(nums[i]<=target)
        {
            p=f(i-1,target-nums[i],nums,dp);
        }
        return dp[i][target]= p || np;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums)
        {
            sum+=it;
        }
        if(sum%2==1) return false;
        sum=sum/2;
        //applying memoization
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return f(n-1,sum,nums,dp);
    }
};