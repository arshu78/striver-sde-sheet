class Solution {
public:
    void bfs(int i,int j,int n,int m,vector<vector<int>>& land,vector<vector<int>>& vis,vector<int>& temp)
    {
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int tl1=-1,tl2=-1,b1=-1,b2=-1;
        int r[]={-1,0,+1,0};
        int c[]={0,+1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(tl1==-1)
            {
                tl1=row;
                tl2=col;
                b1=row;
                b2=col;
            }
            else
            {
                b1=row;
                b2=col;
            }
            
            for(int i=0;i<4;i++)
            {
                int nrow=row + r[i];
                int ncol=col + c[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && land[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        
        temp.push_back(tl1);
        temp.push_back(tl2);
        temp.push_back(b1);
        temp.push_back(b2);
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vector<int> temp;
                if(!vis[i][j] && land[i][j]==1)
                {
                    bfs(i,j,n,m,land,vis,temp);
                    ans.push_back(temp);
                }
                
            }
        }
        return ans;
    }
};