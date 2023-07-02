//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int f(int i,int j,string& s1,string& s2,vector<vector<int>>& dp)
	{
	    if(i<0 || j<0) return 0;
	    if(dp[i][j]!=-1) return dp[i][j];
	    if(s1[i]==s2[j]) return 1 + f(i-1,j-1,s1,s2,dp);
	    
	    return dp[i][j]= max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
	    
	}
	int minOperations(string str1, string str2) 
	{ 
	    int n=str1.size();
	    int m=str2.size();
	    vector<vector<int>> dp(n,vector<int>(m,-1));
	    int diff=f(n-1,m-1,str1,str2,dp);
	    
	    if(diff!=m)
	    {
	        return n- diff + (m-diff);
	    }
	    return str1.size()-diff;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends