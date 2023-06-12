//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int f(int i,int *arr,vector<int>& dp)
	{
	    if(i==0) return arr[i];
	    
	    if(i<0) return 0;
	    if(dp[i]!=-1) return dp[i];
	    int npick= 0 + f(i-1,arr,dp);
	    int pick=INT_MAX;
	    pick= arr[i] + f(i-2,arr,dp);
	    
	    
	    return dp[i]=max(pick,npick);
	}
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n+1,-1);
	    return f(n-1,arr,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends