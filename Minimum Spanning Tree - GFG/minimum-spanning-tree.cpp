//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
        vector<int> vis(V,0);
        pq.push({{0,0},0});
        vector<pair<int,int>> mst;
        int sum=0;
        while(!pq.empty())
        {
            int node=pq.top().first.second;
            int w=pq.top().first.first;
            int p=pq.top().second;
            pq.pop();
            
            if(vis[node]==1) continue;
            
            vis[node]=1;
            sum+=w;
            mst.push_back({p,node});
            for(auto it:adj[node])
            {
                int a_node=it[0];
                int ew=it[1];
                if(!vis[a_node])
                {
                    pq.push({{ew,a_node},node});
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends