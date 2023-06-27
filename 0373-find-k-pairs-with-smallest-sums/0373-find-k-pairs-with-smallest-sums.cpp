class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        // int mini=INT_MAX;
        // for(auto it:nums1) mini=min(mini,it);
        
        priority_queue<pair<int,pair<int,int>>> pq1;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                
                if(pq1.size()<k) pq1.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                else if(nums1[i]+nums2[j] < pq1.top().first)
                {
                    pq1.pop();
                    pq1.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                }
                else if(nums1[i]+nums2[j] > pq1.top().first) break;
            }
        }
        
        while(!pq1.empty())
        {
            ans.push_back({pq1.top().second.first, pq1.top().second.second});
            pq1.pop();
        }
    return ans;
        
    }
};