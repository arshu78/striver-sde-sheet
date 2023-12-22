class Solution {
public:
    int mod=1e9 + 7;
    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};
    
    long long int f(int i,int j,vector<vector<int>> &arr,vector<vector<long long int>>& dp)
    {
        long long int cnt=1;
        if(dp[i][j]!=-1) return dp[i][j] % mod;
        for(int k=0;k<4;k++)
        {
            int nrow=i + dx[k];
            int ncol=j + dy[k];
            
            if(nrow>=0 && nrow<arr.size() && ncol>=0 && ncol<arr[0].size() && arr[nrow][ncol]>arr[i][j])
            {
                cnt+=f(nrow,ncol,arr,dp) % mod;
            }
        }
        return dp[i][j]= cnt%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        long long int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long int>> dp(n,vector<long long int>(m,-1));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                ans+=f(i,j,grid,dp)%mod;
            }
        }
        return ans%mod;
    }
};