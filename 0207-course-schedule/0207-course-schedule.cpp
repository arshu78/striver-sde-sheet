class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indeg(V,0);
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indeg[it]++;
	        }
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(indeg[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    vector<int> ans;
	    while(!q.empty())
	    {
	        int ele=q.front();
	        q.pop();
	        ans.push_back(ele);
	        for(auto it:adj[ele])
	        {
	            indeg[it]--;
	            if(indeg[it]==0) q.push(it);
	        }
	    }
	    
	    
	  if(ans.size()==V) return true;
        return false;
    }
};