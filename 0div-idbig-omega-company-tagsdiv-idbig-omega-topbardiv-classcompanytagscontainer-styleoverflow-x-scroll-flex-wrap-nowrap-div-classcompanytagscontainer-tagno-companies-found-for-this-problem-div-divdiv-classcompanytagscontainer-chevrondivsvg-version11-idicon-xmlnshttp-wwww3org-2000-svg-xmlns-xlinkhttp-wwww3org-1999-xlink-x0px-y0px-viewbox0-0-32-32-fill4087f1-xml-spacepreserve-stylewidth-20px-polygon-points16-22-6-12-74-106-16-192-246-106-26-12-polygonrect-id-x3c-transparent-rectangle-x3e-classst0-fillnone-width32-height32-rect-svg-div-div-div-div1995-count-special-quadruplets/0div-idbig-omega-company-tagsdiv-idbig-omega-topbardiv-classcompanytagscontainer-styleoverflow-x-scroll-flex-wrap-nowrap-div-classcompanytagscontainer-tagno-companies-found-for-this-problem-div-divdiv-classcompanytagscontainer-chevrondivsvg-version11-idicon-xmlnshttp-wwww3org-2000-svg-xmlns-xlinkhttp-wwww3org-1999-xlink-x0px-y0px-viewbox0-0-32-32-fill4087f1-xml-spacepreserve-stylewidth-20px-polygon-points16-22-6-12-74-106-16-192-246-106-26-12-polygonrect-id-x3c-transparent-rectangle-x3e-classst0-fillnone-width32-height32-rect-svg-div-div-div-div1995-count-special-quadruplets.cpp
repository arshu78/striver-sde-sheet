class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n=nums.size();
     int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int sum=nums[i]+nums[j]+nums[k];
                    int o=k+1;
                    while(o<n)
                    {
                        if(nums[o]==sum) ans++;
                        
                        o++;
                    }
                    
                }
            }
        }
        return ans;
    }
};