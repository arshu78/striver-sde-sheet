class Solution {
public:
    bool f(int n,vector<bool>& dp)
    {
        if(n==1 || n==0) return false;
        if(dp[n]!=false) return dp[n];
        for(int ind=1;ind<n;ind++)
        {
            if(n % ind==0)
            {
                return dp[n]= !f(n-ind,dp);
            }
        }
        return dp[n]= false;
    }
    bool divisorGame(int n) {
        vector<bool> dp(n,false);
        return f(n,dp);
    }
};