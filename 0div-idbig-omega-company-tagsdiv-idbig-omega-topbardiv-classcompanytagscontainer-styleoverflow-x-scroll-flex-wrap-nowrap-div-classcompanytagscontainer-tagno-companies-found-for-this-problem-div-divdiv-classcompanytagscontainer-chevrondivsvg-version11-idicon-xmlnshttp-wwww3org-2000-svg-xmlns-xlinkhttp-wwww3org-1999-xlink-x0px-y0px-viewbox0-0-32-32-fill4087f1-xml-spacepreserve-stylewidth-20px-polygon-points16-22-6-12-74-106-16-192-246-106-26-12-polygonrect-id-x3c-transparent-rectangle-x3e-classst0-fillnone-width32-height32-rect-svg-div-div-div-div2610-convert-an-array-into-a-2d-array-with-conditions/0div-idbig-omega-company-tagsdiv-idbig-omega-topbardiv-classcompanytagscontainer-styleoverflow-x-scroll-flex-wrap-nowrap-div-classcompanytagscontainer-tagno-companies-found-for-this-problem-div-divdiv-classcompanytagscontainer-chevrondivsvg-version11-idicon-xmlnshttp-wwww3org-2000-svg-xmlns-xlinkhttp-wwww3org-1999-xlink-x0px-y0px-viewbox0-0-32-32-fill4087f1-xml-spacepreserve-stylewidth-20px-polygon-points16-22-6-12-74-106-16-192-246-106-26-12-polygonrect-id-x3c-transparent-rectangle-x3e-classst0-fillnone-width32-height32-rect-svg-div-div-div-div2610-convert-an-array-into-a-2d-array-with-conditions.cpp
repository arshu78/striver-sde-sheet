class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            bool flag=true;
            map<int,int> mp;
            for(int j=0;j<n;j++)
            {
                if(nums[j]!=INT_MIN && mp.find(nums[j])==mp.end())
                {
                    temp.push_back(nums[j]);
                    mp[nums[j]]++;
                    nums[j]=INT_MIN;
                    flag=false;
                    
                }
            }
            if(flag) break;
            else ans.push_back(temp);
        }
        return ans;
    }
};