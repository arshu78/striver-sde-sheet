//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int row,int col,vector<vector<int>> &M,vector<vector<int>>& dp)
    {
        if(row<0 || col<0) return 0;
        if(row>=M.size() || col>=M[0].size()) return 0;
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        int right=M[row][col] + f(row,col+1,M,dp);
        int up=M[row][col] + f(row-1,col+1,M,dp);
        int down=M[row][col] + f(row+1,col+1,M,dp);
        
        return dp[row][col]= max(right,max(up,down));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
            maxi=max(maxi,f(i,0,M,dp));
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends