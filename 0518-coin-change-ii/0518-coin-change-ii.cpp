class Solution {
public:
    int f(int ind,int target,vector<int>& arr,vector<vector<int>>& dp)
    {
        if(ind==0)
        {
            return (target%arr[0]==0);
        }

        if(dp[ind][target]!=-1) return dp[ind][target];
        int nt=f(ind-1,target,arr,dp);
        int tk=0;
        if(arr[ind]<=target)
        tk=f(ind,target-arr[ind],arr,dp);

        return dp[ind][target]=tk+nt;
    } 
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        for(int t=0;t<=amount;t++)
        {
            dp[0][t]= (t% coins[0]==0);
        }

        for(int ind=1;ind<n;ind++)
        {
            for(int t=0;t<=amount;t++)
            {
                int nt=dp[ind-1][t];
                int tk=0;
                if(coins[ind]<=t)
                tk=dp[ind][t- coins[ind]];

              dp[ind][t]=tk+nt;
            }
        }

        return dp[n-1][amount];
    }
};