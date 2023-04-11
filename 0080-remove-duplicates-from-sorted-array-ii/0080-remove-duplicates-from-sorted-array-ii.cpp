class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=-1;
        unordered_map<int,int> mp;
        
        for(int j=0;j<nums.size();j++)
        {
            mp[nums[j]]++;
            if(mp[nums[j]]<=2)
               {
                    i++;
               }
            if(nums[i]!=nums[j] and mp[nums[j]]<=2)
            {
                nums[i]=nums[j];
            }
         
        }
        return i+1;
    }
};