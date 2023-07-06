class Solution {
public:
    int f(int i,int buy,int n,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(i==n) return 0;
        
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy)
        {
            profit=max(-prices[i] + f(i+1,0,n,prices,dp),0 + f(i+1,1,n,prices,dp)); // [7,3,2,5,1,2] consider for buy at 7 and sell at 5 so profit add 5 - 7 so we need to add -7 to buy
        }
        else
        {
            profit=max(prices[i] + f(i+1,1,n,prices,dp), 0 + f(i+1,0,n,prices,dp)); 
        }
        return dp[i][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        dp[n][0]=dp[n][1]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                 int profit=0;
                if(buy)
                {
                    profit=max(-prices[i] + dp[i+1][0],0 + dp[i+1][1]); // [7,3,2,5,1,2] consider for buy at 7 and sell at 5 so profit add 5 - 7 so we need to add -7 to buy
                }
                else
                {
                    profit=max(prices[i] + dp[i+1][1], 0 + dp[i+1][0]); 
                }
                dp[i][buy]= profit;
            }
        }
        return dp[0][1];
    }
};