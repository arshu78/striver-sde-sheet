class Solution {
public:
    void f(int i,int target,vector<int>& arr,vector<int> temp,vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
       
        for(int ind=i;ind<arr.size();ind++){
            if(ind!=i && arr[ind]==arr[ind-1]) continue;
            if(arr[ind]>target) break;
            
            temp.push_back(arr[ind]);
            f(ind+1,target - arr[ind],arr,temp,ans);
            temp.pop_back();
        }
    
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,target,candidates,temp,ans);
        return ans;
    }
};