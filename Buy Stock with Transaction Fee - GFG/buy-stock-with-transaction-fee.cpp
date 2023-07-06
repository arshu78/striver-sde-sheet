//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long f(int i,int buy,vector<long long>& prices,int n,int fee,vector<vector<int>>& dp)
    {
        if(i==n) return 0;
        long long profit=0;
        
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy)
        {
            profit= max(-prices[i] + f(i+1,0,prices,n,fee,dp),0 + f(i+1,1,prices,n,fee,dp));
        }
        else
        {
            profit=max(prices[i] + f(i+1,1,prices,n,fee,dp) - fee, 0 + f(i+1,0,prices,n,fee,dp));
        }
        return dp[i][buy]= profit;
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,n,fee,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends