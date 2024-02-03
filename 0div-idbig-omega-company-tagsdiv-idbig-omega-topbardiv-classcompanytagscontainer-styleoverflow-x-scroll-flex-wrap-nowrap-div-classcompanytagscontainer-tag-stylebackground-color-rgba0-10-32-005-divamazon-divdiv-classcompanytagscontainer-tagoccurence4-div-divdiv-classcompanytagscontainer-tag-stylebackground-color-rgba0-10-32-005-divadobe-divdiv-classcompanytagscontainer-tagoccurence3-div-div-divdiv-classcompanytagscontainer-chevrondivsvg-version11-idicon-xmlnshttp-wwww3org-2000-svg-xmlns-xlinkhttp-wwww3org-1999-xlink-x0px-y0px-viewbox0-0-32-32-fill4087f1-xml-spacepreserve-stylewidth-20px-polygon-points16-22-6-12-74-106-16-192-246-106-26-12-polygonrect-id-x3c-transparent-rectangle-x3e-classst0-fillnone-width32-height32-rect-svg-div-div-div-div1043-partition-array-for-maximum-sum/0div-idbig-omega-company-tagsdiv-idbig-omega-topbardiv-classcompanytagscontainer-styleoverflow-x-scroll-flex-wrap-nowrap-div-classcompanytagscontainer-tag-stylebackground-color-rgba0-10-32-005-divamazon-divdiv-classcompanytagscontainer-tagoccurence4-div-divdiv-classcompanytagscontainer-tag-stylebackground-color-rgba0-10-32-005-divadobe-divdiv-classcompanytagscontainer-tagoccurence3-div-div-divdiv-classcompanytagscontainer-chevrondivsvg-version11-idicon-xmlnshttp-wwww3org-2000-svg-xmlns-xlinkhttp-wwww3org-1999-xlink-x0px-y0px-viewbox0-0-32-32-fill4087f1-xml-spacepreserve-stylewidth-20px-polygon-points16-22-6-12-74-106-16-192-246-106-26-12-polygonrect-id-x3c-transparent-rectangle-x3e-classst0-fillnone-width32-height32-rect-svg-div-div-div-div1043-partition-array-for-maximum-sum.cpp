class Solution {
public:
    int f(int i,vector<int>& arr,int k,vector<int>& dp)
    {
        int n=arr.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=INT_MIN,ans=INT_MIN;
        int len=0;
        for(int j=i;j<min(i+k,n);j++)
        {
            len++;
            maxi=max(maxi,arr[j]);
            
            ans=max(ans,maxi*len + f(j+1,arr,k,dp));
        }
        return dp[i]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,-1);
        return f(0,arr,k,dp);
    }
};