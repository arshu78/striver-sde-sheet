class Solution {
public:
    bool bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        queue<pair<int,int>> q;
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        bool res=true;
        int n=grid.size();
        int m=grid[0].size();
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            
            if(row==0 || col==0 || col==m-1 || row==n-1) res=false;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow= r[i] +row;
                int ncol= c[i] + col;
                
                if(nrow >= 0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        return res;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0 && !vis[i][j])
                {
                    bool temp=bfs(i,j,grid,vis);
                    if(temp)
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};