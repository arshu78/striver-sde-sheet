//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define mod 1000000007
class Solution{
public:
    long int solve(int n,vector<long long>& dp)
    {
        if(n==1) return 0;
        if(n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= (n-1)%mod * ((solve(n-2,dp)%mod) + (solve(n-1,dp)%mod))%mod;
    }
    long int disarrange(int n){
        vector<long long> dp(n+1,-1);
        return solve(n,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends