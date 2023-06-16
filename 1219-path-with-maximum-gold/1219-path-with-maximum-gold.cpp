class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& g,vector<vector<int>>& vis,int sum)
    {
        int n=g.size(),m=g[0].size();
        if(i < 0 || i == n || j < 0 || j == m || !g[i][j] || vis[i][j]) return 0;
        vis[i][j] = 1;
        int ans = g[i][j] + max({dfs(i - 1, j, g, vis, sum), dfs(i + 1, j, g, vis, sum),
                             dfs(i, j - 1, g, vis, sum), dfs(i, j + 1, g, vis, sum)});
        vis[i][j] = 0;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int r=0,c=0,maxi=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                    int sum=0;
                    if(grid[i][j]!=0)
                    maxi=max(maxi,dfs(i,j,grid,vis,sum));
                
            }
        }
        return maxi;
    }
};