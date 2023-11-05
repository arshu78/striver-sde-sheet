class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int> mp;
        sort(changed.begin(),changed.end());
        for(auto it:changed)
        {
            mp[it]++;
        }
        vector<int> ans;
        
        for(auto it:changed)
        {
           if(mp[it]==0) continue;
            mp[it]--;
            
            if(mp[it*2]==0) return {};
            
            mp[it*2]--;
            ans.push_back(it);
        }
      //  if(!mp.empty()) return {};
        return ans;
    }
};