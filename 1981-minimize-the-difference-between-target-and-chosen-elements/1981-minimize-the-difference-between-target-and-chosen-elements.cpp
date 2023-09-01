class Solution {
public:
    int dp[72][5000];
    int f(int i,int sum,vector<vector<int>>& mat,int target)
    {
        if(i<0)
        {
            return abs(sum-target);
        }
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        int ans=INT_MAX;
        
        for(int k=0;k<mat[0].size();k++)
        {
            ans=min(ans,f(i-1,sum+mat[i][k],mat,target));
        }
        return dp[i][sum]= ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n=mat.size(),m=mat[0].size();
        int sum=0;
        memset(dp, -1, sizeof(dp));
        return f(n-1,sum,mat,target);
    }
};