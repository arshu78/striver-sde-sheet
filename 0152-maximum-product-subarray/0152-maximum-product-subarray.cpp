class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int ans=nums[0];
        int mx=ans;
        int mn=ans;
        
        int n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
            {
                swap(mx,mn);
            }
            
            mx=max(nums[i],nums[i]*mx);
            mn=min(nums[i],nums[i]*mn);
            
            ans=max(ans,mx);
        }
        
        return ans;
        
        
//             int n = nums.size();
//         int ma = nums[0], mi = nums[0], ans = nums[0];
//         for(int i=1;i<n;i++){
//             int ele = nums[i];
//             if(ele < 0) swap(ma, mi);
            
//             ma = max(ele, ma * ele);
//             mi = min(ele, mi * ele);
            
//             ans = max(ans, ma);
//         }
        
//         return ans;
    }
};