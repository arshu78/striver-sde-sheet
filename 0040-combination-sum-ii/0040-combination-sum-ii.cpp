class Solution {
public:
    void f(int ind,int target,int n,vector<int> arr,vector<vector<int>>& ans,vector<int> ds)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<n;i++)
        {
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            
            ds.push_back(arr[i]);
            f(i+1,target-arr[i],n,arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        f(0,target,candidates.size(),candidates,ans,ds);
       return ans;
    }
};