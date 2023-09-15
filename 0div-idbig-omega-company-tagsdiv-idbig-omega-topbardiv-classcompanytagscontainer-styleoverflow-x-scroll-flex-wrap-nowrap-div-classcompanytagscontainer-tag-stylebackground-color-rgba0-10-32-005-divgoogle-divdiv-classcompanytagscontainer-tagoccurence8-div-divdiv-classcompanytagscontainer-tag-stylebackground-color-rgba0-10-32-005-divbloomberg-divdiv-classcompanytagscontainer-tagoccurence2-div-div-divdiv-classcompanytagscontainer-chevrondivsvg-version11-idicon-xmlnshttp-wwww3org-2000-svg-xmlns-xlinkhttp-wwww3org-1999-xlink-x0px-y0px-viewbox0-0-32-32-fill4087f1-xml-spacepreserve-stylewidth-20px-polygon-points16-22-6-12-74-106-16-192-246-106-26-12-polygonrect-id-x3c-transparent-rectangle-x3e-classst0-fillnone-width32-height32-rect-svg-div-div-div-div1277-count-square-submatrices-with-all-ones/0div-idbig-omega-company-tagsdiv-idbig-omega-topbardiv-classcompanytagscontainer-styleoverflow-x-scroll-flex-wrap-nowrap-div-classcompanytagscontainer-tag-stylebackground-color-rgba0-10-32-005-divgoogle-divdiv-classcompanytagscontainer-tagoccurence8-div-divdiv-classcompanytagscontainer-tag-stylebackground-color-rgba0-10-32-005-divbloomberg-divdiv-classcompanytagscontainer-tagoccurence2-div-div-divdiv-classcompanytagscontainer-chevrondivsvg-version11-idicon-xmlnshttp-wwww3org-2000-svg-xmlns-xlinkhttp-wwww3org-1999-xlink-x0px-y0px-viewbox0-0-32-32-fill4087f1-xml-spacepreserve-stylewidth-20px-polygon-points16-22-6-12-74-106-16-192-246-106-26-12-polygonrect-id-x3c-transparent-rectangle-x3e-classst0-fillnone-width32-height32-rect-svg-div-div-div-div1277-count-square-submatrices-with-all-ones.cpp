class Solution {
public:
    int f(int i,int j,int n,int m,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(i>=n || j>=m) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int right=f(i,j+1,n,m,matrix,dp);
        int down=f(i+1,j,n,m,matrix,dp);
        int d = f(i+1,j+1,n,m,matrix,dp);
        
        if(matrix[i][j]==1)
        {
            return dp[i][j]= 1 + min(right,min(down,d));
        }
        return dp[i][j]= 0;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        int total=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1)
                total += f(i,j,n,m,matrix,dp);
            }
        }
        
        return total;
    }
};