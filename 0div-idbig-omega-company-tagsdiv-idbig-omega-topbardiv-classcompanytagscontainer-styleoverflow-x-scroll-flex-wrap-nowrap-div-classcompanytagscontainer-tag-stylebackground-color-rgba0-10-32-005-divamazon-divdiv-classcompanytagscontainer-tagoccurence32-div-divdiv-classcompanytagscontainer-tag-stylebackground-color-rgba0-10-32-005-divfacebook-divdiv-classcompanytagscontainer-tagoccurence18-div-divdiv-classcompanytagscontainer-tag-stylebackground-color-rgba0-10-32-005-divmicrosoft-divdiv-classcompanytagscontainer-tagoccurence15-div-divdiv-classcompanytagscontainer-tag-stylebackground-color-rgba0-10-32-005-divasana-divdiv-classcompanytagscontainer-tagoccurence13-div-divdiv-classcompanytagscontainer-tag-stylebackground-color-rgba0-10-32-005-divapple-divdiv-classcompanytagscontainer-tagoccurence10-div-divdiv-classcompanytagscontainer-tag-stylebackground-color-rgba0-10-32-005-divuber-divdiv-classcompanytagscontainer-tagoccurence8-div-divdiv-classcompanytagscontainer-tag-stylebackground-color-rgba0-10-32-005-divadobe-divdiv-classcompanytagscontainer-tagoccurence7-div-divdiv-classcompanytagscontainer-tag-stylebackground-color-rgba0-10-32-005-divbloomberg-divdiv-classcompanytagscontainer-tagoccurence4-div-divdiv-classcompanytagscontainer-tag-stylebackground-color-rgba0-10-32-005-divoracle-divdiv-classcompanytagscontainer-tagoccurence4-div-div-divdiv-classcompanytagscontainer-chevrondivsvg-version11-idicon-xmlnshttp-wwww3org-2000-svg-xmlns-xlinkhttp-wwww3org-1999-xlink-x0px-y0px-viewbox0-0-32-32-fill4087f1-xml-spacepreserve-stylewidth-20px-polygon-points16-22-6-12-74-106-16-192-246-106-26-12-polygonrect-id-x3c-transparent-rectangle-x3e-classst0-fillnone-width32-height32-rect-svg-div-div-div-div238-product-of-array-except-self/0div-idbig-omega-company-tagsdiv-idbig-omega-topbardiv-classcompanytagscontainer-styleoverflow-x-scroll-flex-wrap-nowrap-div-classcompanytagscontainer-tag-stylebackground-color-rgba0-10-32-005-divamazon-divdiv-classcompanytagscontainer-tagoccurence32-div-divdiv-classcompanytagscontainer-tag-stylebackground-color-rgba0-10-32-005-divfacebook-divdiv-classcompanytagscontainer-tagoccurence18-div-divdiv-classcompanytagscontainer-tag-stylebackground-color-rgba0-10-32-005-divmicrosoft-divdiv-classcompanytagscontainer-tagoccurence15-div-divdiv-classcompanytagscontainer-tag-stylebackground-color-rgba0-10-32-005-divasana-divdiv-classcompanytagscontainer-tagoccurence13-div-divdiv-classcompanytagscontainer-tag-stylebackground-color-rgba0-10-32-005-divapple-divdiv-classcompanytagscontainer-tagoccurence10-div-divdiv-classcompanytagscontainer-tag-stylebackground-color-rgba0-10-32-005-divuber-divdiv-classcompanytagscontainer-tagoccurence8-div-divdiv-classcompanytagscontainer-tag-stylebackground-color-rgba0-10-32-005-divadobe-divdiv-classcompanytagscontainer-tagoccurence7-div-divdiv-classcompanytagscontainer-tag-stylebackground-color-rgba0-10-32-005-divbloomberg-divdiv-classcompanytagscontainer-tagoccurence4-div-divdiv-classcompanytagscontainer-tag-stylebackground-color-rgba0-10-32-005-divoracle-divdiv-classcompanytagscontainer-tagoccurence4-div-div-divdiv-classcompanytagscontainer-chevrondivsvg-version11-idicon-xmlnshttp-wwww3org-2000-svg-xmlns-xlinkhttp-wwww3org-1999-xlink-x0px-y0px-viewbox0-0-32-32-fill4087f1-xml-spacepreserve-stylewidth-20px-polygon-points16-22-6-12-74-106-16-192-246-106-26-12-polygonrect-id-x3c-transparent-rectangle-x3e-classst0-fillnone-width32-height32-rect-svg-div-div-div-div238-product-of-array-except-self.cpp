class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int z=0;
        long long int p=1;
        for(auto it:nums)
        {
            if(it==0) z++;
            else p*=it;
        }
        vector<int> ans;
        for(auto it:nums)
        {
            if(z>1)
            {
                ans.push_back(0);
            }
            else if(z==1)
            {
                if(it==0) ans.push_back(p);
                else ans.push_back(0);
            }
            else
            {
                ans.push_back(p/it);
            }
        }
        return ans;
    }
};