class Solution {
public:
    int getMaximumGenerated(int n) {
        
        if(n==0)return 0;
        if(n==1)return 1;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        int maxi=1;
        for(int i=2;i<=n;i++)
        {
            if(i%2==0)
            {
                dp[i]=dp[i/2];
            }
            else
            {
                dp[i]=dp[(i/2)+1] +  dp[i/2];
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
        
    }
};