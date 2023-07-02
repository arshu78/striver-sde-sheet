//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int mod=1e9 + 7;
   long long int f(int i,int j,vector<vector<long long>>& dp)
    {
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j]% mod;
       long long int up=f(i-1,j,dp)% mod;
        long long int left=f(i,j-1,dp)% mod;
        
        return dp[i][j]= (up + left) % mod;
    }
    long long int numberOfPaths(int m, int n){
        vector<vector<long long>> dp(m,vector<long long>(n,-1));
        return f(m-1,n-1,dp) % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends