class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // vector<pair<int,int>> adj[];
        // int n=flights.size();
        // for(auto it: flights)
        // {
        //     adj[it[0]].push_back({it[1],it[2]});
        // }
        // vector<int> dist(n+1,1e9);

        // queue<pair<int,pair<int,int>> q;
        // q.push({0,{src,0}});
        // while(!q.empty())
        // {
        //     auto it=q.front();
        //     int stops=it.first;
        //     int node=it.second.first;
        //     int dist=it.second.second;

        //     if(stops>k) continue;
        //     for(auto itr:adj[node])
        //     {
        //         int adjnode=itr.first;
        //         int wt=itr.second;

        //         if(dist + wt < dist[adjn])
        //     }

   
          vector<int> dist( n, INT_MAX );
        dist[src] = 0;
        
       
        for( int i=0; i <= k; i++ ) {
            vector<int> tmp( dist );
            for( auto flight : flights ) {
                if( dist[ flight[0] ] != INT_MAX ) {
                    tmp[ flight[1] ] = min( tmp[flight[1]], dist[ flight[0] ] + flight[2] );
                }
            }
            dist = tmp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];

     
    }
};