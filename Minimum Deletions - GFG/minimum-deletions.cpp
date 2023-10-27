//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[1001][1001];
    int f(int i,int j,string& s1,string& s2)
    {
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
        {
            return dp[i][j]= 1 + f(i-1,j-1,s1,s2);
        }
        return dp[i][j]= max(f(i-1,j,s1,s2),f(i,j-1,s1,s2));
    }
    int minimumNumberOfDeletions(string s) { 
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        int lcs=f(n-1,n-1,s,s2);
        return n - lcs;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends