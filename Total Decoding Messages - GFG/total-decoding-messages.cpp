//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int mod=1e9 + 7;
	    int f(int i,string& s,vector<int>& dp)
	    {
	        if(i>=s.size()) return 1;
	        if(dp[i]!=-1) return dp[i];
	        int ans=0;
	        if(s[i]!='0') ans+=f(i+1,s,dp) % mod;
	        
	        if(i+1<s.size() &&(s[i]=='1' || s[i]=='2' && s[i+1] <='6')) ans+=f(i+2,s,dp) % mod;
	        
	        return dp[i]= ans% mod;
 	    }
		int CountWays(string str){
		    int n=str.length();
		    vector<int> dp(n+1,-1);
		    return f(0,str,dp) % mod;
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
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends