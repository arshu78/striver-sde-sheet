class Solution {
public:
  bool dfs(int i,vector<vector<int>>& adj,vector<int>& vis,vector<int>& path,vector<int>& check)
  {
      vis[i]=1;
      path[i]=1;
      
      for(auto it:adj[i])
      {
          if(!vis[it])
          {
              if(dfs(it,adj,vis,path,check)==true)
              {
                  check[it]=0;
                  return true;
              }
          }
          else if(path[it]==1)
         {
                  check[it]=0;
                  return true;
         }
      }
      check[i]=1;
      path[i]=0;
      return false;
  }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> vis(V,0);
        vector<int> path(V,0);
        vector<int> check(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,graph,vis,path,check);
            }
        }
        
        for(int i=0;i<V;i++)
        {
            if(check[i]==1) ans.push_back(i);
        }
        
        return ans;
    }
};