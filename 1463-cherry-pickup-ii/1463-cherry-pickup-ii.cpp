class Solution {
public:
    int r,c;
    vector<int> dy={-1,0,1};
    bool check(int y)
    {
        return y>=0 && y<c;
    }
    int f(int x,int p,int q,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
    {
        if(x>=r || !check(p) || !check(q)) return 0;
        
        if(dp[x][p][q]!=-1) return dp[x][p][q];
        
        int ans=0,cur=0;
        if(p==q)
        {
            cur=grid[x][p];
        }
        else cur=grid[x][p] + grid[x][q];
        
        for(int i=0;i<3;i++)
        {
            int curx=p + dy[i];
            for(int j=0;j<3;j++)
            {
                int cury=q + dy[j];
                
                ans=max(ans,cur + f(x+1,curx,cury,grid,dp));
            }
        }
        return dp[x][p][q]= ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        r=grid.size(),c=grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(r,vector<int>(c,-1)));
        return f(0,0,c-1,grid,dp);
    }
};