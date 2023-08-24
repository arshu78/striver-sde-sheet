class Solution {
public:
    int f(int i,int j,int &maxi,vector<vector<char>>& mat,vector<vector<int>>& dp)
    {
        if(i>=mat.size() || j>=mat[0].size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int right=f(i,j+1,maxi,mat,dp);
        int down=f(i+1,j,maxi,mat,dp);
        int d=f(i+1,j+1,maxi,mat,dp);
        
        int ans=0;
        if(mat[i][j]=='1')
        {
            ans=1 + min(right,min(down,d));
            maxi=max(maxi,ans*ans);
        }
        return dp[i][j]=ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        f(0,0,maxi,matrix,dp);
        return maxi;
    }
};