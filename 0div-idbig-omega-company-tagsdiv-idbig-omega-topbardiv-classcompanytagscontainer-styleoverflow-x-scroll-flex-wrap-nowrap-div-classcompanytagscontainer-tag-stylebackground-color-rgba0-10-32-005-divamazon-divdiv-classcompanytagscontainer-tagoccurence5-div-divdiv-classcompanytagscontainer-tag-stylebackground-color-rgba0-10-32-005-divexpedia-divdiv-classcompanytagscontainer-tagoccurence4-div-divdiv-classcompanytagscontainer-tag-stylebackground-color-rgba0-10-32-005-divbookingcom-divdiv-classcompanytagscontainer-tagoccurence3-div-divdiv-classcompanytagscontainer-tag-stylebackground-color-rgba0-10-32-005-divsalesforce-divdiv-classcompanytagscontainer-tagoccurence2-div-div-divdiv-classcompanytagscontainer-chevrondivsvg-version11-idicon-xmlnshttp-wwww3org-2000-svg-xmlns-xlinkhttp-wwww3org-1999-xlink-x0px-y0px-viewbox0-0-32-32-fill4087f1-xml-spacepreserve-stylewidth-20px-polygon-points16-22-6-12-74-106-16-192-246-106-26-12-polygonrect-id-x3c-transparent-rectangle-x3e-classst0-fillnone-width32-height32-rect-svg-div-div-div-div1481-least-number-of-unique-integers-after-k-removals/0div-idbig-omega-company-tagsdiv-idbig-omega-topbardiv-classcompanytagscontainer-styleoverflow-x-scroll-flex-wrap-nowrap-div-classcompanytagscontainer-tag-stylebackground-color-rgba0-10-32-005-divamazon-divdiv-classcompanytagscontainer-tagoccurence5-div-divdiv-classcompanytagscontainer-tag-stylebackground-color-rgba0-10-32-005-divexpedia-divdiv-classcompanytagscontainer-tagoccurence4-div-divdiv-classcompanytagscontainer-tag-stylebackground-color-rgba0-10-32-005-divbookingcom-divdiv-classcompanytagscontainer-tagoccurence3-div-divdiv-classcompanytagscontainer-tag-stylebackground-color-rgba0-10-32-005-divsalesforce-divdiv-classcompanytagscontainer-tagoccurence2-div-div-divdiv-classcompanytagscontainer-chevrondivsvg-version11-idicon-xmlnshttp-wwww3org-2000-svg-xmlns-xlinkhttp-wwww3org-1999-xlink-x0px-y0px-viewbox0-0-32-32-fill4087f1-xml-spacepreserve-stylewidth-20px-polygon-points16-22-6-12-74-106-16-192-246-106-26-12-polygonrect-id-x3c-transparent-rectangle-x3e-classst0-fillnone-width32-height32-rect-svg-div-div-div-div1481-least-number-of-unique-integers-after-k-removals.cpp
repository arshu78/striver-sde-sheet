class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto it:arr) mp[it]++;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:mp) pq.push(it.second);
        
        while(!pq.empty() && k>0)
        {
            auto it=pq.top();
            pq.pop();
            if(k<it)
            {
                k=0;
                pq.push(it-k);
            }
            else k-=it;
        }
        return pq.size();
        
    }
};