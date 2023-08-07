//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int j,vector<vector<int>>& mat,int &maxi,vector<vector<int>>& dp)
    {
        if(i>=mat.size() || j>=mat[0].size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right=f(i,j+1,mat,maxi,dp);
        int bottom=f(i+1,j,mat,maxi,dp);
        int d=f(i+1,j+1,mat,maxi,dp);
        
        if(mat[i][j]==1)
        {
            int ans= 1 + min(bottom,min(right,d));
            maxi=max(maxi,ans);
            
            return dp[i][j]= ans;
        }
        else
        {
            return dp[i][j]= 0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        //tabulation
        
        //copy the base case
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                 int right=dp[i][j+1];
                    int bottom=dp[i+1][j];
                    int d=dp[i+1][j+1];
                    
                    if(mat[i][j]==1)
                    {
                        int ans= 1 + min(bottom,min(right,d));
                        maxi=max(maxi,ans);
                        
                        dp[i][j]= ans;
                    }
                    else
                    {
                        dp[i][j]= 0;
                    }
            }
        }
       // f(0,0,mat,maxi,dp);
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
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends