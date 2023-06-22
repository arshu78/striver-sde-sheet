class Solution {
public:
 int f(int i,int buy,int fee,vector<int>& arr,int n,vector<vector<int>>& dp)
    {
        if(i==n)
        {
            return 0;
        }
        int profit=0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==0)
        {
            profit= max(-arr[i]+f(i+1,1,fee,arr,n,dp),0+f(i+1,0,fee,arr,n,dp));
        }
        else
        {
            profit= max(arr[i]-fee+f(i+1,0,fee,arr,n,dp),0+f(i+1,1,fee,arr,n,dp));
        }
        return dp[i][buy]= profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,0,fee,prices,n,dp);
    }
};