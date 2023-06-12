class Solution {
public:
    int f(int n,vector<int>& dp)
    {
        if(n==0) return 1;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int st1=f(n-1,dp);
        int st2=f(n-2,dp);
        
        return dp[n] = st1 + st2;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};