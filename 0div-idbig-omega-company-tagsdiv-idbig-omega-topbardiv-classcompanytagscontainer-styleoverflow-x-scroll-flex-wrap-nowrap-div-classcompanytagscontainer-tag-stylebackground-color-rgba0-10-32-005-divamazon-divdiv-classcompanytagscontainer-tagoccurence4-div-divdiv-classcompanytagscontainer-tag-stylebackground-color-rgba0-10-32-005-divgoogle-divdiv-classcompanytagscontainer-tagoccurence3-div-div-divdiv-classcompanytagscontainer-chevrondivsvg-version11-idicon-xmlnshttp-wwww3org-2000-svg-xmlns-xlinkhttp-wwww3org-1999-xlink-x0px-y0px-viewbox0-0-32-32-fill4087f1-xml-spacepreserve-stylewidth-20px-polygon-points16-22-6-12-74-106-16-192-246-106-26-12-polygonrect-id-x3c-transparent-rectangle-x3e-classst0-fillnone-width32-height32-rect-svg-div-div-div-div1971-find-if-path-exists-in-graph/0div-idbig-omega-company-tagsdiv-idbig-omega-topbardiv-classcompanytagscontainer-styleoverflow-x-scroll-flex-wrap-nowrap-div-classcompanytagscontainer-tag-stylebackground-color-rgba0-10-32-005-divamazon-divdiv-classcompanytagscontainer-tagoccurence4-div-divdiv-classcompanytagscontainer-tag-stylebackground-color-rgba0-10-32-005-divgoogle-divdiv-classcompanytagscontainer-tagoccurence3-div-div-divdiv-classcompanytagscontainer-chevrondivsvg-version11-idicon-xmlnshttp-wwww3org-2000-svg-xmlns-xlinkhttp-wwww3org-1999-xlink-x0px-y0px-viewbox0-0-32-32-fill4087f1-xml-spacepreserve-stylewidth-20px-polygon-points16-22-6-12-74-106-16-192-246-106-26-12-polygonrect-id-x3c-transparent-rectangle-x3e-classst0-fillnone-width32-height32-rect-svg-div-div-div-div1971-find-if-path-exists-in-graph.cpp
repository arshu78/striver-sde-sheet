class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       int m=edges.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(source);
        vis[source]=true;
        	vector<int> total[n];
        for(int i=0;i<m;i++)
        {
            total[edges[i][0]].push_back(edges[i][1]);
            total[edges[i][1]].push_back(edges[i][0]);
        }
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            
            if(a==destination) 
            {
                return true;
            }
            for(auto it:total[a])
            {
                if(!vis[it])
                {
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
        return false;
       
        
    }
};