class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        vector<int> pre(n);
        pre[0]=0;
        
        for(int i=1;i<nums.size();i++)
        {
            int last=maxi - nums[i];
            pre[i]=max(pre[i-1],last);
            if(nums[i]>maxi)
            {
                maxi=nums[i];
            }
        }
        long long ans=0;
        for(int i=1;i<nums.size();i++)
        {
            ans=max(ans,(long long) pre[i-1] * nums[i]);
        }
        return ans;
    }
};