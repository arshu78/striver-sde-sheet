class Solution {
public:
    int dp[501][501];
    int f(int i,int j,string &s1,string &s2)
    {
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
        {
            return dp[i][j]= 1 + f(i-1,j-1,s1,s2);
        }
        return dp[i][j]= max(f(i-1,j,s1,s2),f(i,j-1,s1,s2));
    }
    int minInsertions(string s) {
        string t=s;
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        reverse(t.begin(),t.end());
        int lcs=f(n-1,n-1,s,t);
        return n - lcs;
    }
};