class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(auto it:nums)
        {
            mp[it]++;
        }
        
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};