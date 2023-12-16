class Solution {
public:
    int f(int i,vector<int>& arr,int prev,vector<vector<int>>& dp)
    {
        if(i>=arr.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int mini=INT_MAX;
        if(i-prev<= prev+1)
            mini=min(mini,f(i+1,arr,prev,dp));
        
        return dp[i][prev+1]= min(mini,arr[i] + f(i+1,arr,i,dp));
    }
    int minimumCoins(vector<int>& prices) {\
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,prices,-1,dp);
    }
};