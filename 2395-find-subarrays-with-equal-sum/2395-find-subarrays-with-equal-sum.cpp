class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            if(i+1<nums.size())
            {
                for(int j=i;j<i+2;j++)
            {
                sum+=nums[j];
            }
            if(mp.find(sum)!=mp.end()) return true;
            else mp[sum]++;
            }
            
        }
        return false;
    }
};