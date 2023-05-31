//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,stack<int>& st)
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	void revdfs(int node,vector<int> trans[],vector<int>& vis)
	{
	    vis[node]=1;
	    for(auto it:trans[node])
	    {
	        if(!vis[it])
	        {
	            revdfs(it,trans,vis);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //topo sort
        
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,st);
            }
        }
        
        // transpose the graph;
        vector<int> trans[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            for(auto it:adj[i])
            {
                
                trans[it].push_back(i);
            }
        }
        int cnt=0;
        while(!st.empty())
        {
            
            int i=st.top();
            st.pop();
            if(!vis[i])
            {
                cnt++;
                revdfs(i,trans,vis);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends