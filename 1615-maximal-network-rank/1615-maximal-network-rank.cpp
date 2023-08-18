class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        vector<int> deg(n,0);
        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            
            deg[u]++;
            deg[v]++;
            
            vis[u][v]=1;
            vis[v][u]=1;
        }
        
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int total=deg[i] + deg[j];
                
                if(vis[i][j]==1)
                {
                    total--;
                }
                
                maxi=max(maxi,total);
            }
        }
        
        return maxi;
    }
};