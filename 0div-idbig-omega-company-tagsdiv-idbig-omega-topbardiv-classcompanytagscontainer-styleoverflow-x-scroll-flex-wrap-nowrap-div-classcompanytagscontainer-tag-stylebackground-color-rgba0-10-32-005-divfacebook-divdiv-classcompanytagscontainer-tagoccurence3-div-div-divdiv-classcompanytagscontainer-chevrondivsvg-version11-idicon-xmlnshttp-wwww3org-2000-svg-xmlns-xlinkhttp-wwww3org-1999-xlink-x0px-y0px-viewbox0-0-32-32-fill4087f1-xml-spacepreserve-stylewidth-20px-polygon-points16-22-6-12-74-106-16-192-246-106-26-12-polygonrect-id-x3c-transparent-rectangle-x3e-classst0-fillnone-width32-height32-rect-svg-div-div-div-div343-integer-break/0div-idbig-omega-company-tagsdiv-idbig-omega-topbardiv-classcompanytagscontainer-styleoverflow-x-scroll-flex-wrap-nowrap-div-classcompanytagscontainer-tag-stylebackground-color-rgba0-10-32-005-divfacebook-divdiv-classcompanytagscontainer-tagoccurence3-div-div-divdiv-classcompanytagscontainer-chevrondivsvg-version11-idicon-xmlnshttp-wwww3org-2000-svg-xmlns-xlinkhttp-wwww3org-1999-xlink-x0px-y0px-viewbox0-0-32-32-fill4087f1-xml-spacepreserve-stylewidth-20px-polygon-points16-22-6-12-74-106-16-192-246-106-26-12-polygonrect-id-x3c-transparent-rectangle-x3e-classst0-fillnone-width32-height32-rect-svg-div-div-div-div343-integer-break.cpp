class Solution {
public:
    int dp[100];
    int f(int n)
    {
        if(n==1) return 1;
        
        if(dp[n]!=-1) return dp[n];
        int p=n;
 
        for(int ind=2;ind<=n;ind++)
        {
            
                p=max(p,ind * f(n-ind));
           
        }
        
        return dp[n]= p;
    }
    int integerBreak(int n) {
        if(n<=3) return n-1;
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};