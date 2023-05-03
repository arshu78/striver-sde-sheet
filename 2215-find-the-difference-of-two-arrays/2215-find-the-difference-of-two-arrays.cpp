class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
      sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        
        vector<int> a;
        for(auto it:s1)
        {
            if(s2.find(it)==s2.end()) a.push_back(it);
        }
          vector<int> b;
        for(auto it:s2)
        {
            if(s1.find(it)==s1.end()) b.push_back(it);
        }
        
        return {a,b};
    }
};