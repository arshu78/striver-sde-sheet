class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        int i=1;
        while(i<nums.size()-1)
        {
            if(abs(nums[i-1]-nums[i])<=k && abs(nums[i]-nums[i+1])<=k && abs(nums[i-1]-nums[i+1])<=k)
            {
                ans.push_back({nums[i-1],nums[i],nums[i+1]});
            }
            else return {};
            
            i+=3;
        }
        return ans;
    }
};