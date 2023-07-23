class Solution {
public:
     void generate(vector<vector<int>> & a,vector<int>&nums,int i,vector<int> b)
    {
        if(i==nums.size())
        {
            a.push_back(b);
            return;
        }
        generate(a,nums,i+1,b);
        b.push_back(nums[i]);
        generate(a,nums,i+1,b);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        generate(ans,nums,0,temp);
        return ans;
        
    }
};