class Solution {
public:
    int f(int ind,int size,vector<int>& a,int n,vector<vector<int>>& dp)
    {
        if(n==0 || ind>size) return 0;
        
        if(dp[ind][n]!=-1) return dp[ind][n];
        
        int take=a[ind] + f(ind+2,size,a,n-1,dp);
        int ntake=0 + f(ind+1,size,a,n,dp);
        
        return dp[ind][n]= max(take,ntake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        vector<vector<int>> dp1(k+1,vector<int>(k+1,-1));
        int case1=f(0,k-2,slices,k/3,dp1);
        vector<vector<int>> dp2(k+1,vector<int>(k+1,-1));
        int case2=f(1,k-1,slices,k/3,dp2);
        
        return max(case1,case2);
    }
};