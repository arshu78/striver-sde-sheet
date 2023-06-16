class Solution {
public:
    int f(int i,int j,int m,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(j<0 || j>=m)
        return 1e9;
    if(i==0)
        return matrix[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = matrix[i][j] + f(i-1,j,m,matrix,dp);
    int leftDiagonal = matrix[i][j] + f(i-1,j-1,m,matrix,dp);
    int rightDiagonal = matrix[i][j] + f(i-1,j+1,m,matrix,dp);
    
    return dp[i][j]= min(up,min(leftDiagonal,rightDiagonal));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    int maxi = INT_MAX;

    for(int j=0;j<m;j++)
    {
        dp[0][j]=matrix[0][j];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int up = matrix[i][j] + dp[i-1][j];
            int leftDiagonal = matrix[i][j];
            if(j-1>=0) 
            leftDiagonal+=dp[i-1][j-1];
            else
            leftDiagonal+=1e8;
             int rightDiagonal = matrix[i][j];
             if(j+1<m) rightDiagonal+=dp[i-1][j+1];
             else
             rightDiagonal+=1e8;

             dp[i][j]=min(up,min(rightDiagonal,leftDiagonal));
        }
    }

    maxi=INT_MAX;
    for(int j=0; j<m;j++){

        maxi = min(maxi,dp[n-1][j]);
    }
    
    return maxi;
    }
};