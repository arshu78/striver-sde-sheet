class Solution {
public:
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=grid[i][j] + f(i-1,j,grid,dp);
        int left= grid[i][j] + f(i,j-1,grid,dp);

        return dp[i][j]= min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>> dp(n,vector<int> (m,-1));
        // //recursion
        // return f(n-1,m-1,grid,dp);

        vector<vector<int>> dp(n,vector<int> (m,0));


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0) dp[0][0]=grid[0][0];
                else 
                {
                    int up,left;
                    if(i>0)
                    {
                        up=grid[i][j]+dp[i-1][j];
                    }
                    else
                    {
                        up=1e9;
                    }

                    if(j>0)
                    {
                        left=grid[i][j] + dp[i][j-1];

                    }
                    else{
                        left=1e9;
                    }
                    dp[i][j]=min(up,left);
                    
                }
            }
        }
    return dp[n-1][m-1];

         //space optimiztion

        vector<int> prev(m);
        for(int i=0;i<n;i++)
        {
            vector<int> cur(m);
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0) cur[j]=grid[i][j];
                else 
                {
                    int up,left;
                    if(i>0)
                    {
                        up=grid[i][j]+prev[j];
                    }
                    else
                    {
                        up=1e9;
                    }

                    if(j>0)
                    {
                        left=grid[i][j] + cur[j-1];

                    }
                    else{
                        left=1e9;
                    }

                    cur[j]=min(up,left);
                }
            }
            prev=cur;
        }

        return prev[m-1];
    }
};