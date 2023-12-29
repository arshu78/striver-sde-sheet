class Solution {
public:
    pair<int,int> c(string& s)
    {
        int i=0,j=0;
        for(auto it:s)
        {
            if(it=='0') i++;
            else j++;
        }
        return {i,j};
    }
    int f(int i,vector<string>& s,int m,int n,vector<vector<vector<int>>>& dp)
    {
        if(i>=s.size()) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int np=0 + f(i+1,s,m,n,dp);
        auto it=c(s[i]);
        int p=it.first;
        int q=it.second;
        int pq=0;
        if(m-p>=0 && n-q>=0)
        {
            pq=1 + f(i+1,s,m-p,n-q,dp);
        }
        
        return dp[i][m][n]= max(pq,np);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        
        return f(0,strs,m,n,dp);
    }
};