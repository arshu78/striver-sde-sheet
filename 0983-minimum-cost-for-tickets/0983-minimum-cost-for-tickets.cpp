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
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,-1);
        return f(0,n,days,costs,dp);
    }
};