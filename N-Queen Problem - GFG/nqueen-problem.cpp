//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isSafe(int i,int j,vector<vector<int>> vis,int n)
    {
        int row=i,col=j;
        
        while(row>=0 && col>=0)
        {
            if(vis[row][col]==1) return false;
            
            row--;
            col--;
        }
        
        row=i,col=j;
        
        while(col>=0)
        {
            if(vis[row][col]==1) return false;
            col--;
        }
        
        row=i,col=j;
        
        while(row<n && col>=0)
        {
            if(vis[row][col]==1) return false;
            
            row++;
            col--;
        }
        
        return true;
    }
    void solve(int col,int n,vector<int> temp,vector<vector<int>> &ans,vector<vector<int>> vis)
    {
        if(col>=n) 
        {
            ans.push_back(temp);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,vis,n))
            {
                vis[row][col]=1;
                temp.push_back(row+1);
                solve(col+1,n,temp,ans,vis);
                temp.pop_back();
                vis[row][col]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans,v(n,vector<int>(n,0));
        vector<int> temp;
        
        solve(0,n,temp,ans,v);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends