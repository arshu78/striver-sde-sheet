class Solution {
public:
    int f(int i,vector<int>& coins,int target,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(target % coins[i]==0) return target / coins[i];
            else return 1e9;
        }
        
        if(dp[i][target]!=-1) return dp[i][target];
            int nt= 0 + f(i-1,coins,target,dp);
        int tk=INT_MAX;
        
        if(coins[i]<=target)
        {
            tk = 1 + f(i, coins,target - coins[i],dp);   
        }
        
        return dp[i][target]= min(tk,nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans= f(n-1,coins,amount,dp);
        if(ans>=1e9) return -1;
        
        return ans;
    }
};