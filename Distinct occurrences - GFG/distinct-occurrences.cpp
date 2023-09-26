//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int mod=1e9 + 7;
    int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
    {
         if(j==0) return 1;
        if(i==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1])  return dp[i][j]=(f(i-1,j-1,s1,s2,dp) % mod + f(i-1,j,s1,s2,dp) % mod)% mod;
        
        return dp[i][j]= f(i-1,j,s1,s2,dp) % mod;
    }
    int subsequenceCount(string S, string T)
    {
      int n=S.size();
      int m=T.size();
      vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
      return f(n,m,S,T,dp) % mod;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends