class Solution {
public:
    int f(int i,vector<int>& s,vector<vector<int>>& j,vector<int>& dp)
    {
        if(i>=s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ind=lower_bound(s.begin(),s.end(),j[i][1]) - s.begin();
        int p=j[i][2] + f(ind,s,j,dp);
        int np=f(i+1,s,j,dp);
        
        return dp[i]= max(p,np);
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n=s.size();
        vector<vector<int>> j;
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++)
        {
            j.push_back({s[i],e[i],p[i]});
        }
        sort(j.begin(),j.end());
        sort(s.begin(),s.end());
        
        return f(0,s,j,dp);
    }
};