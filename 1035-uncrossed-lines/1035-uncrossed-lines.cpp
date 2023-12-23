class Solution {
public:
    int f(int i,int j,vector<int>& arr1,vector<int>& arr2,vector<vector<int>>& dp)
    {
        if(i>=arr1.size() || j>=arr2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(arr1[i]==arr2[j]) return dp[i][j]= 1 + f(i+1,j+1,arr1,arr2,dp);
        
        return dp[i][j]= max(f(i+1,j,arr1,arr2,dp),f(i,j+1,arr1,arr2,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,nums1,nums2,dp);
    }
};