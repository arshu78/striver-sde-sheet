class Solution {
public:
    
    void dfs(int a,vector<int>& ans,map<int,vector<int>> &adj,map<int,bool> &mp)
    {
        mp[a]=true;
        ans.push_back(a);
        for(auto &it:adj[a])
        {
            
            if(!mp[it])
            {
                dfs(it,ans,adj,mp);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& arr) {
        int n=arr.size();
        map<int,vector<int>> adj;
         map<int,bool> mp;
        for(auto &it:arr)
        {
            mp[it[0]]=false;
            mp[it[1]]=false;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
       
        vector<int> ans;
        int src=0;
        for(auto &it:adj)
        {
            if(it.second.size()==1)
            {
                src=it.first;
                break;
            }
        }
        dfs(src,ans,adj,mp);
        return ans;
    }
};