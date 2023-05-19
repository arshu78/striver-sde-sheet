class Solution {
public:
    bool dfs(int s,int a,int color[],vector<vector<int>>& graph)
    {
        color[s]=a;

        for(auto it:graph[s])
        {
            if(color[it]==-1)
            {
                if(dfs(it,!a,color,graph)==false) return false;
            }
            else if(color[it]==color[s]) return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        //TC -O(v+2E);
        
        int n=graph.size();
        int color[n];

        for(int i=0;i<n;i++) color[i]=-1;

        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,0,color,graph)==false) return false;
            }
        }
        return true;
    }
};