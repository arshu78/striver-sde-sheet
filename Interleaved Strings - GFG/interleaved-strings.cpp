//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    
    bool f(int i,int j,int len,string &s1,string &s2,string &s3,vector<vector<int>> &dp)
    {
        if(len==0) return true;
        
        if(dp[i][j]!=-1) return dp[i][j];
        bool a=false,b=false;
        
        if(i-1>=0 && s1[i-1]==s3[len-1]) a=f(i-1,j,len-1,s1,s2,s3,dp);
        
        if(j-1>=0 && s2[j-1]==s3[len-1]) b=f(i,j-1,len-1,s1,s2,s3,dp);
        
        return dp[i][j]= a || b;
    }
    bool isInterleave(string A, string B, string C) 
    {
       int n=A.size(),m=B.size(),len=C.size();
       vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
       return f(n,m,len,A,B,C,dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends