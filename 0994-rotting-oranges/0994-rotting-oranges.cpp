class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2) q.push({{i,j},0});
                
            }
        }
        int ans=0;
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            ans=max(ans,time);
            for(int i=0;i<4;i++)
            {
                int nrow=r[i] + row;
                int ncol=c[i] + col;
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1)
                {
                    grid[nrow][ncol]=2;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        
        return ans;
    }
};