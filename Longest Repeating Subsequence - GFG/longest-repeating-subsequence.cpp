//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int lcs(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
	    {
	        if(i<0 || j<0) return 0;
	        
	        if(dp[i][j]!=-1) return dp[i][j];
	        if(s1[i]==s2[j] && i!=j)
	        {
	            return dp[i][j]= 1 + lcs(i-1,j-1,s1,s2,dp);
	        }
	        else
	        return dp[i][j]= max(lcs(i-1,j,s1,s2,dp),lcs(i,j-1,s1,s2,dp));
	       
	    }
		int LongestRepeatingSubsequence(string str){
		    int n=str.length();
		    vector<vector<int>> dp(n,vector<int>(n,-1));
		    return lcs(n-1,n-1,str,str,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends