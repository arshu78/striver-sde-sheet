class Solution {
public:
    int mod=1e9 + 7;
    long long f(int i,int j,int m,int n,int max,vector<vector<vector<long long>>>& dp)
    {
        
        if(i<0 || j<0 || i>=m || j>=n) return 1;
         if(max==0) return 0;
        if(dp[i][j][max]!=-1) return dp[i][j][max]% mod;
         long long up=f(i-1,j,m,n,max-1,dp) % mod;
         long long d=f(i+1,j,m,n,max-1,dp) % mod;
         long long l=f(i,j-1,m,n,max-1,dp) % mod;
         long long r=f(i,j+1,m,n,max-1,dp) % mod;
        
        return dp[i][j][max]=(( up+d+l+r) % mod) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long>>> dp(m+1,vector<vector<long long>>(n+1,vector<long long>(maxMove+1,-1)));
        return f(startRow,startColumn,m,n,maxMove,dp) % mod;
    }
};