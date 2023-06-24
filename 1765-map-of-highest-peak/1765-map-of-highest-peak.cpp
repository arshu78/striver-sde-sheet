class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                    isWater[i][j]=0;
                }
            }
        }
        
        int r[]={-1,0,+1,0};
        int ci[]={0,+1,0,-1};
        
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int c=q.front().second;
            isWater[row][col]=c;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow= row + r[i];
                int ncol= col + ci[i];
               
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},c+1});
                    
                }
            }
        }
        
        return isWater;
    }
};