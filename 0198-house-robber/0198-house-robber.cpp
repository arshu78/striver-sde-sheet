class Solution {
public:
    int f(int ind,vector<int> nums,vector<int>& dp)
    {
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind] + f(ind-2,nums,dp);
        int nonpick=0 + f(ind-1,nums,dp);

        return dp[ind]= max(pick,nonpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        

       int prev=nums[0];
       int prev2=0;
        for(int i=1;i<n;i++)
        {
            int take=nums[i];
            if(i>1) take+=prev2;

            int notpick=0 + prev;

            int curi = max(take,notpick);
            prev2=prev;
            prev=curi;
        }

        return prev;
    }
        
    
};