//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void f(int i,int j,vector<vector<int>>& m,vector<vector<int>>& vis,vector<string>& ans,string s,int n)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(s);
            return;
        }
        
        int r[]={1,0,0,-1};
        int c[]={0,-1,1,0};
        string d="DLRU";
        for(int ind=0;ind<4;ind++)
        {
            int row=i + r[ind];
            int col=j + c[ind];
            
            if(row>=0 && col>=0 && row<n && col<n && !vis[row][col] && m[row][col]==1)
            {
                vis[i][j]=1;
                f(row,col,m,vis,ans,s+d[ind],n);
                vis[i][j]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<string> temp;
        string ans="";
        if(m[0][0]==1) f(0,0,m,vis,temp,ans,n);
        
        return temp;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends