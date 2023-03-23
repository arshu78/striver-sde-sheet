class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        vector<pair<int,int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back({nums[i],i});
        }
        sort(ans.begin(),ans.end());
        
        while(low<high)
        {
            if(ans[low].first + ans[high].first==target) return {ans[low].second,ans[high].second};
            else if(ans[low].first + ans[high].first < target) low+=1;
            else high--;
        }
        return {-1,-1};
    }
};