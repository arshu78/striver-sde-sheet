class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>& a,int n,int m)
    {
        if(i>=n||j>=m||i<0||j<0||a[i][j]==0) return false;
        if(i==n-1&&j==m-1) return true;
        a[i][j]=0;
        return dfs(i+1,j,a,n,m)||dfs(i,j+1,a,n,m);
        
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if(!dfs(0,0,grid,grid.size(),grid[0].size())) return true;
        grid[0][0]=1;
        if(!dfs(0,0,grid,grid.size(),grid[0].size())) return true;
        return false;
    }
};