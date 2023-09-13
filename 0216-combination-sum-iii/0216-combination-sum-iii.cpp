class Solution {
public:
    void f(int ind,int k,int n,vector<int> &temp,vector<vector<int>>& ans)
    {
        if(temp.size()==k)
        {
            if(n==0)
            {
                ans.push_back(temp);
                
            }
            return;
        }
        
        for(int i=ind;i<=9;i++)
        {
            temp.push_back(i);
            f(i+1,k,n-i,temp,ans);
            temp.pop_back();
        }
      //  f(ind+1,k,n,temp,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        f(1,k,n,temp,ans);
        return ans;
    }
};