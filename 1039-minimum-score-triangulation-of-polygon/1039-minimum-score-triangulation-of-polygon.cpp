class Solution {
public:
    int f(int i,int j,vector<int>& v,vector<vector<int>>& dp)
    {
        if(i+1==j) // base case if it consist only 2 vertex then 0 triangle form
        {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            ans=min(ans,v[i]*v[j]*v[k] + f(i,k,v,dp)+f(k,j,v,dp));
        }
        
        return dp[i][j]= ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,values.size()-1,values,dp);
    }
};