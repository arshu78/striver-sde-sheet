class Solution {
public:
    void f(int i,vector<int> nums,vector<int> temp,set<vector<int>>& st,int n)
    {
        if(i==n)
        {
             sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        f(i+1,nums,temp,st,n);
        temp.pop_back();
        f(i+1,nums,temp,st,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> temp;
        f(0,nums,temp,st,nums.size());
        vector<vector<int>> ans;
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
        
    }
};