//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int f(int i,int prev,int arr[],int n,vector<vector<int>>& dp)
	{
	    if(i>=n) return 0;
	    
	    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
	    int nt= 0 + f(i+1,prev,arr,n,dp);
	    int tk=0;
	    if(prev==-1 || arr[i] > arr[prev])
	    {
	        tk= arr[i] + f(i+1,i,arr,n,dp);
	    }
	    
	    return dp[i][prev+1]= max(nt,tk);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    int prev=-1;
	    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	    return f(0,prev,arr,n,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends