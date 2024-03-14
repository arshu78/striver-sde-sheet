class Solution {
public:
    int solve(vector<int>& nums, int goal)
    {
        int i=0,j=0;
        int cur=0,res=0;
        if(goal<0) return 0;
        while(j<nums.size())
        {
            cur+=nums[j];
            while(cur>goal)
            {
                cur-=nums[i++];
            }
            res+=j-i+1;
            j++;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
            return solve(nums,goal)-solve(nums,goal-1);       
    }
};