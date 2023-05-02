class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long int ans=0;
        for(auto it:nums)
        {
            if(it==0) return 0;
            if(it<0) ans++;
        }
        if(ans%2==0) return 1;
        
        
        return -1;
    }
};