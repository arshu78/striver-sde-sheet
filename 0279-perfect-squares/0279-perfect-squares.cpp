class Solution {
public:
    int solve(int n,vector<int>& dp)
    {
        if(n==0) return 0;
        
        int ans=INT_MAX;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++)
        {
            ans=min(ans,1 + solve(n-i*i,dp)); // 
        }
        
        return dp[n]= ans;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        
        for(int j=1;j<=n;j++)
        {
            int ans=INT_MAX;
            for(int i=1;i*i<=n;i++)
            {
                if(j-i*i>=0)
                ans=min(ans,1 + dp[j-i*i]); // 
            }
        
            dp[j]= ans;
        }
        return solve(n,dp);
    }
};