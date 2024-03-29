//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int f(int n,vector<int>& dp)
	{
	    if(n==0) return 0;
	    int ans=INT_MAX;
	    if(dp[n]!=-1) return dp[n];
	    for(int i=1;i*i<=n;i++)
	    {
	        ans=min(ans,1+ f(n-i*i,dp));
	    }
	    
	    return dp[n]= ans;
	}
	int MinSquares(int N)
	{
	    vector<int> dp(N+1,0);
	    
	    for(int n=1;n<=N;n++)
	    {
	        int ans=INT_MAX;
    	    for(int i=1;i*i<=n;i++)
    	    {
    	        if(n-i*i>=0)
    	        ans=min(ans,1+ dp[n-i*i]);
    	    }
    	    
    	   dp[n]= ans;
	    }
	   return dp[N];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends