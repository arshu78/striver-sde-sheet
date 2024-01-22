class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> mp;
        for(int i=1;i<=nums.size();i++)
        {
            mp[i]=0;
        }
        for(auto it:nums)
        {
            mp[it]++;
        }
        
        int r=-1,m=-1;
        for(auto it:mp) 
        {
            if(it.second>1) r=it.first;
            if(it.second==0) m=it.first;
        }
        
        return {r,m};
    }
};