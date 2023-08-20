class Solution {
public:
  int f(vector<vector<int>>& offers,vector<int> &dp,int n)
    {
        vector<int> e,s;
        for(auto it :offers)
        {
            s.push_back(it[0]);
            e.push_back(it[1]);
        }
        
        for(int i=offers.size()-1;i>=0;i--)
        {
            int ind=upper_bound(s.begin(),s.end(),e[i])- s.begin();
            dp[i]= max(offers[i][2] + dp[ind],dp[i+1]);
        }
        
        return *max_element(dp.begin(),dp.end());
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        vector<int> dp(offers.size()+1,0);
        return f(offers,dp,n);
    }
};