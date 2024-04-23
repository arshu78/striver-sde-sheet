class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
                vector<int> ans;
        if(n==0) return ans;
        if(n==1) return {0};
        vector<int> d(n,0);
        vector<vector<int>> adj(n);
        for(auto it:edges)
        {
            d[it[0]]++;
            d[it[1]]++;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(d[i]==1) q.push(i);
        }
        while(n>2)
        {
            int size=q.size();
            n-=size;
            
            for(int i=0;i<size;i++)
            {
                int v=q.front();
               q.pop();
                
                for(auto it:adj[v])
                {
                    d[it]--;
                    if(d[it]==1) q.push(it);
                }
            }
        }
        while(!q.empty()) 
        {
            int a=q.front();
            q.pop();
            ans.push_back(a);
        }
        return ans;
    }
};