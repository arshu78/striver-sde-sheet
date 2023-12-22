class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int f(int i,int j,vector<vector<int>>& arr,vector<vector<int>> &dp)
    {
        int ans=1;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=0;k<4;k++)
        {
            int nrow=i + dx[k];
            int ncol=j + dy[k];
            
            if(nrow>=0 && nrow<arr.size() && ncol>=0 && ncol<arr[0].size() && arr[nrow][ncol]>arr[i][j])
            {
                ans=max(ans,1 + f(nrow,ncol,arr,dp));
            }
        }
        return dp[i][j]= ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,f(i,j,matrix,dp));
            }
        }
        return ans;
    }
};