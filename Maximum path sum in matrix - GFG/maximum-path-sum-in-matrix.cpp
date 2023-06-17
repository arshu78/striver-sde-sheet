//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int j,vector<vector<int>>& arr, vector<vector<int>>& dp)
    {
        if(j<0 || j>=arr[0].size()) return INT_MIN;
        if(i==0) 
        {
            return arr[i][j];
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int t=arr[i][j] + f(i-1,j,arr,dp);
        int tl=arr[i][j] + f(i-1,j-1,arr,dp);
        int tr=arr[i][j] + f(i-1,j+1,arr,dp);
        
        return dp[i][j]= max(t,max(tl,tr));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int n=Matrix.size();
        int m=Matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int maxi=INT_MIN;
        for(int i=0;i<m;i++)
        {
            maxi=max(maxi,f(n-1,i,Matrix,dp));
        }
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends