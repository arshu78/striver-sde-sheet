class Solution {
public:
    void bfs(int i,int j,int n,int m,vector<vector<char>>& grid,vector<vector<int>>& vis)
    {
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int r[]={-1,0,+1,0};
        int c[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row + r[i];
                int ncol=col + c[i];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]=='1' && vis[nrow][ncol]!=1)
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size(),cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    bfs(i,j,n,m,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};