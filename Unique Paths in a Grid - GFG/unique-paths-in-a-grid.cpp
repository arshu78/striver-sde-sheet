//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int mod=1e9+7;
    long long int f(long long int i,long long int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i>=0 && j>=0 && grid[i][j]==0) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long int up=f(i-1,j,grid,dp) % mod;
        long long int left=f(i,j-1,grid,dp) % mod;
        
        return dp[i][j] = up+ left % mod;
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(i==0 && j==0 && grid[i][j]!=0) 
               {
                   dp[i][j]=1;
                   continue;
               }
               else if(grid[i][j]==0)
               {
                    dp[i][j]=0;
                    continue;
               } 
               else
               {
                   int up=0;
                   int left=0;
                   if(i>0) up=dp[i-1][j] % mod;
                   if(j>0) left=dp[i][j-1] % mod;

                   dp[i][j]=(up+left) % mod;
               }
           } 
        }

       return dp[n-1][m-1] % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends