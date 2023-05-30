class Solution {
public:
    bool check(int i,int c,vector<vector<int>>& adj,vector<int>& color)
    {
       color[i]=c;
        for(auto it:adj[i])
        {
            if(color[it]==-1)
            {
                if(check(it,!c,adj,color)==false) return false;
            }
            else if(color[it]==color[i]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(check(i,0,graph,color)==false) return false;
            }
        }
        return true;
    }
};