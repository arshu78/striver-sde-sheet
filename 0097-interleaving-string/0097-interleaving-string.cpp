class Solution {
public:
    bool f(int i,int j,int k,string s1,string s2,string s3,vector<vector<int>> &dp)
    {
        if(k==0) return true;
        
        if(dp[i][j]!=-1) return dp[i][j];
        bool a=false,b=false;
        if(i-1>=0 && s1[i-1]==s3[k-1]) a=f(i-1,j,k-1,s1,s2,s3,dp);
        if(j-1>=0 && s2[j-1]==s3[k-1]) b=f(i,j-1,k-1,s1,s2,s3,dp);
        
        return dp[i][j]= a || b;
     }
    bool isInterleave(string s1, string s2, string s3) {
        int len=s3.size();
      //  if(s1=="" && s2=="" && s3=="") return true;
        int n=s1.size(),m=s2.size();
      vector<vector<int>> dp(n+1,vector<int>(m+1,-1));  
        if(n+m!=len) return false;
       return f(n,m,len,s1,s2,s3,dp);
    }
};