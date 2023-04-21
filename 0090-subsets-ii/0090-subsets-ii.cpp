class Solution {
public:
    void f(int ind,vector<int> nums,vector<int> ds,vector<vector<int>>& ans,int n)
    {
          ans.push_back(ds);
         for (int i = ind; i < n; i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            f(i + 1, nums, ds, ans,n);
            ds.pop_back();
         }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> st;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        f(0,nums,temp,st,nums.size());
        return st;
        
    }
};