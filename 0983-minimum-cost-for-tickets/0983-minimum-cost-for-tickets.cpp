class Solution {
public:
    int f(int ind,int n,vector<int>& days,vector<int>& cost,vector<int>& dp)
    {
        if(ind>=n) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        int op1=cost[0] + f(ind+1,n,days,cost,dp);
        
        
        int i;
        for(i=ind;i<n && days[i] < days[ind] + 7;i++);
        
        int op2=cost[1] + f(i,n,days,cost,dp);
        
         for(i=ind;i<n && days[i] < days[ind] + 30;i++);
        
        int op3=cost[2] + f(i,n,days,cost,dp);
        
        
        return dp[ind]= min(op1,min(op2,op3));
        
            
    }
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n=days.size();
        vector<int> dp(n+1,INT_MAX);
        
        dp[n]=0;
        
        for(int ind=n-1;ind>=0;ind--)
        {
            int op1=cost[0] + dp[ind+1];
        
        
        int i;
        for(i=ind;i<n && days[i] < days[ind] + 7;i++);
        
        int op2=cost[1] + dp[i];
        
         for(i=ind;i<n && days[i] < days[ind] + 30;i++);
        
        int op3=cost[2] + dp[i];
        
        
        dp[ind]= min(op1,min(op2,op3));
        }
        return dp[0];
    }
};