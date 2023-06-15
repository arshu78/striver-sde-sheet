class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i==n-1) return triangle[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int b=f(i+1,j,n,triangle,dp) + triangle[i][j];
        int br=f(i+1,j+1,n,triangle,dp) + triangle[i][j];
        
        return dp[i][j]= min(b,br);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,0,n,triangle,dp);
    }
};