class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        int s,e,diff=INT_MAX;
        for(int i=0;i<nums.size()-2;i++)
        {
            s=i+1;
            e=nums.size()-1;
            int temp=target-nums[i];
            while(s<e)
            {
                
                int val=nums[s]+nums[e]+nums[i];
                if(nums[s]+nums[e]==temp)
                {
                    ans=nums[s]+nums[e]+nums[i];
                    break;
                }
                else if(nums[s]+nums[e]<temp)
                {
                    s++;
                }
                else
                {
                   
                    e--;
                }
                
                if(abs(val - target) < diff)
                {
                    diff=abs(val - target);
                    ans=val;
                }
            }
        }
        return ans;
    }
};