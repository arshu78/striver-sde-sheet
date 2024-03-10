class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        
        for(auto it:nums1) mp[it]++;
        
       set<int> st;
        for(auto it:nums2) {
            if(mp.find(it)!=mp.end())
            {
                st.insert(it);
            }
        }
        vector<int> ans(st.begin(),st.end());
        return ans;
    }
};