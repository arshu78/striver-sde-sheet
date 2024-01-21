class Solution {
public:
    int dp[101];
    int f(int i,vector<int>& nums)
    {
        if(i==0) return nums[0];
       // if(i==1) return nums[1];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]= max(f(i-1,nums),nums[i] + f(i-2,nums));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return f(n-1,nums);
    }
};