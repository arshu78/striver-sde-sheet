class Solution {
public:
    int dp[1001][1001];
    int f(int i,int j,int prev,vector<vector<int>>& grid,int n,int m)
    {
        if(j==m-1) return 0;
        
        
        if(dp[i][j]!=-1) return dp[i][j];
        int top=0,right=0,down=0;
        
        
        if(i-1 >=0 && j+1< m && grid[i-1][j+1]>prev)
        {
            top=1 + f(i-1,j+1,grid[i-1][j+1],grid,n,m);  
            
        }
         if(j+1<m && grid[i][j+1]>prev)
        {
            right=1 + f(i,j+1,grid[i][j+1],grid,n,m);  
            
        }
         if(i+1<n && j+1<m && grid[i+1][j+1]>prev)
        {
            down=1 + f(i+1,j+1,grid[i+1][j+1],grid,n,m);  
            
        }
        
        return dp[i][j]= max({down,top,right});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int moves=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<grid.size();i++)
        {
            moves=max(moves,f(i,0,grid[i][0],grid,n,m));
        }
        return moves;
    }
};