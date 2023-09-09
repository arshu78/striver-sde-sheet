class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int z=0;
        long long int pro=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) z++;
            else pro*=nums[i];
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(z==0)
            {
                nums[i]=pro / nums[i];
            }
            else if(z==1)
            {
                if(nums[i]==0)
                {
                    nums[i]=pro;
                }
                else
                {
                    nums[i]=0;
                }
            }
            else
            {
                nums[i]=0;
            }
        }
        
        return nums;
    }
};