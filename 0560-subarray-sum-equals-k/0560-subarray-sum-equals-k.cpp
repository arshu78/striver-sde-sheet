class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    
            int sum=0,maxi=0;
            map<int,int> mp;
            mp[0]=1;
            for(int i=0;i<nums.size();i++)
            {
                sum+=nums[i];
                int x=sum - k;
                maxi+= mp[x];
                mp[sum]++;
            }
        return maxi;
    }
};