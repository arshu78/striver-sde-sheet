class Solution {
public:
    int f(vector<int>& s,int i,int time,vector<vector<int>> &dp)
    {
        if(i>=s.size()) return 0;
        
        if(dp[i][time]!=-1) return dp[i][time];
        //same as knapsach problem pick or not pick and find the maximum ltc
        int include = s[i] * (time+1) + f(s,i+1,time+1,dp);
        int exclude=  0 + f(s,i+1,time,dp);
        
        return dp[i][time]= max(include,exclude);
    }
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int time=i;time>=0;time--)
            {
                 int include = s[i] * (time+1) + dp[i+1][time+1];
                int exclude=  0 + dp[i+1][time];

                dp[i][time]= max(include,exclude);
            }
        }
        return dp[0][0];
    }
};