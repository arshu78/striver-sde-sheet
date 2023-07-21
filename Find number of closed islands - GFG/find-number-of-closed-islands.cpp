//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
     bool bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        
        int n=grid.size();
        int m=grid[0].size();
        
        vis[i][j]=1;
        bool res=true;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            
            if(row==0 || col==0 || row==n-1 || col==m-1) res=false;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow=r[i] + row;
                int ncol=c[i] + col;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        return res;
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        vector<vector<int>> vis(N,vector<int>(M,0));
        
        int ans=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(matrix[i][j]==1 && !vis[i][j])
                {
                    if(bfs(i,j,matrix,vis))
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends