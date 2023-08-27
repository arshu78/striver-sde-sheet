class Solution {
public:
    bool f(int i,int k,vector<int>& a,vector<vector<int>> &dp)
    {
        if(i==a.size()-1) return true;
        
        
        if(dp[i][k]!=-1) return dp[i][k];
        bool flag=false;
        
        for(int j=i+1;j<a.size();j++)
        {
            if(a[j]>(a[i]+k+1))break;
            else if(a[j] == (a[i] + k-1)) 
            {
                flag|=f(j,k-1,a,dp);
            }
            else if(a[j]==(a[i] +k))
            {
                flag|=f(j,k,a,dp);
            }
            else if(a[j]==(a[i] + k+1))
            {
                flag|=f(j,k+1,a,dp);
            }
        }
        
        return dp[i][k]= flag;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> dp(n,vector<int>(n*2,-1));
        return f(0,0,stones,dp);
    }
};