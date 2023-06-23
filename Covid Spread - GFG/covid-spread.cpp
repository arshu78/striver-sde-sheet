//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0,ans=INT_MAX;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1) cnt++;
            }
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
        int r[]={-1,0,+1,0};
        int c[]={0,+1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            ans=t;
            for(int i=0;i<4;i++)
            {
                int nrow=r[i] + row;
                int ncol=c[i] + col;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},t+1});
                    cnt--;
                }
            }
        }
        if(cnt!=0) return -1;
        
        return ans;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends