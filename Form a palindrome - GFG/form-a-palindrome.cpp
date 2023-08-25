//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int f(int i,int j,string& s1,string& s2,vector<vector<int>> &dp)
    {
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]= 1 + f(i-1,j-1,s1,s2,dp);
        
        return dp[i][j]= max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    int findMinInsertions(string S){
        string s2=S;
        reverse(s2.begin(),s2.end());
        int n=S.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int lcs=f(n-1,n-1,S,s2,dp);
        
        return n-lcs;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends