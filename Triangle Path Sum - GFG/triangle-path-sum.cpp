//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(int i,int j,int n,vector<vector<int>>& a,vector<vector<int>>& dp)
    {
        if(i==n-1) return a[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int d=f(i+1,j,n,a,dp) + a[i][j];
        int dg=f(i+1,j+1,n,a,dp) + a[i][j];
        
        return dp[i][j] = min(d,dg);
    }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,0,n,triangle,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends