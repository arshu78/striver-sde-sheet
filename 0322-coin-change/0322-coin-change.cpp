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
        
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
//         int ans= f(n-1,coins,amount,dp);
//         if(ans>=1e9) return -1;
        
//         return ans;
        
        for(int T=0;T<=amount;T++)
        {
            if(T % coins[0]==0) dp[0][T]=T/coins[0];
            else dp[0][T]=1e9;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int T=0;T<=amount;T++)
            {
                int nt=0 + dp[i-1][T];
                int tk=INT_MAX;
                if(coins[i]<=T)
                    tk=1 + dp[i][T-coins[i]];
                
                dp[i][T]=min(tk,nt);
            }
        }
        
        if(dp[n-1][amount]>=1e9) return -1;
        
        return dp[n-1][amount];
     }
};