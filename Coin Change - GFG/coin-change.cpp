//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int f(int i,int target,int coins[], vector<vector<long long int>>& dp)
    {
        if(i==0)
        {
            return target % coins[i]==0;
        }
        
        if(dp[i][target]!=-1) return dp[i][target];
       long long int nt= 0 + f(i-1,target,coins,dp);
        long long int tk=0;
        if(coins[i]<=target)
        {
            tk=f(i,target-coins[i],coins,dp);
        }
        
        return dp[i][target]= nt + tk;
    }
    long long int count(int coins[], int N, int sum) {

        vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1,-0));
        
        for(int i=0;i<=sum;i++)
        {
            dp[0][i]=(i % coins[0]==0);
        }
        
        for(int i=1;i<N;i++)
        {
            for(int t=0;t<=sum;t++)
            {
                 long long int nt= 0 + dp[i-1][t];
        long long int tk=0;
        if(coins[i]<=t)
        {
            tk=dp[i][t-coins[i]];
        }
        
        dp[i][t]= nt + tk;
            }
        }
        return dp[N-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends