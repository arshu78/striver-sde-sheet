class Solution {
public:
    void f(int i,int target,int n,vector<int> arr, vector<vector<int>>& ans,vector<int> ds)
    {
        if(i==n)
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        
        if(arr[i]<=target)
        {
            ds.push_back(arr[i]);
            f(i,target-arr[i],n,arr,ans,ds);
            ds.pop_back();
        }
        f(i+1,target,n,arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(0,target,candidates.size(),candidates,ans,ds);
        return ans;
    }
};