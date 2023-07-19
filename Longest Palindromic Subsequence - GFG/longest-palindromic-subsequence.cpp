//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int f(int i,int j,string& a,string & b,vector<vector<int>>& dp)
    {
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j]= 1 + f(i-1,j-1,a,b,dp); 
        
        return dp[i][j]= max(f(i-1,j,a,b,dp),f(i,j-1,a,b,dp));
    }
    int longestPalinSubseq(string A) {
        string b=A;
        reverse(b.begin(),b.end());
        vector<vector<int>> dp(A.size()+1,vector<int>(A.size()+1,-1));
        return f(A.size()-1,b.size()-1,A,b,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends