class Solution {
public:
    void bfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& vis,int& cnt)
    {
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int r[]={-1,0,+1,0};
        int c[]={0,+1,0,-1};
        while(!q.empty())
        {
            int nrow=q.front().first;
            int ncol=q.front().second;
            q.pop();
            
                    for(int k=0;k<m;k++)
                    {
                        if(grid[nrow][k]==1 && !vis[nrow][k])
                        {
                             q.push({nrow,k});
                            cnt++;
                            vis[nrow][k]=1;
                        }
                        
                       
                    }
                    for(int k=0;k<n;k++)
                    {
                        if(grid[k][ncol]==1 && !vis[k][ncol])
                        {
                            q.push({k,ncol});
                            cnt++;
                            vis[k][ncol]=1;
                        }
                        
                        
                    }    
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cnt=1;
                if(!vis[i][j] && grid[i][j]==1)
                {
                    bfs(i,j,n,m,grid,vis,cnt);
                    if(cnt!=1)
                    ans+=cnt;
                }
            }
        }
        
        return ans;
    }
};