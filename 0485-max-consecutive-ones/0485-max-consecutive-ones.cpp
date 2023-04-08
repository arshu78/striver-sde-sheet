class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         int temp=0;
        int mx=0;
        for(int j=0;j<nums.size();j++)
        {
           if(nums[j]==1)
           {
               temp++;
               mx=max(mx,temp);
           }
            else
            {
                temp=0;
            }
            
        }
        return mx;
    }
};