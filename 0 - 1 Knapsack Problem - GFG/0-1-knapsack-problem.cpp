//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int f(int i,int w,int wt[],int val[],vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(wt[i]<=w)
            {
                return val[i];
            }
            else
            return 0;
        }
        if(dp[i][w]!=-1) return dp[i][w];
        int nt=0 + f(i-1,w,wt,val,dp);
        
        int tk=INT_MIN;
        
        if(wt[i]<=w)
        tk= val[i] + f(i-1,w- wt[i], wt,val,dp);
        
        
        return dp[i][w]= max(tk,nt);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n+1,vector<int>(W+1,0));
        
        for(int i=wt[0];i<=W;i++)
        {
                dp[0][i] = val[0];

        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=W;j++)
            {
                int nt=0 + dp[i-1][j];
                int t=INT_MIN;
                
                if(wt[i]<=j)
                t= val[i] + dp[i-1][j-wt[i]];
                
                dp[i][j]= max(t,nt);
            }
        }
       return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends