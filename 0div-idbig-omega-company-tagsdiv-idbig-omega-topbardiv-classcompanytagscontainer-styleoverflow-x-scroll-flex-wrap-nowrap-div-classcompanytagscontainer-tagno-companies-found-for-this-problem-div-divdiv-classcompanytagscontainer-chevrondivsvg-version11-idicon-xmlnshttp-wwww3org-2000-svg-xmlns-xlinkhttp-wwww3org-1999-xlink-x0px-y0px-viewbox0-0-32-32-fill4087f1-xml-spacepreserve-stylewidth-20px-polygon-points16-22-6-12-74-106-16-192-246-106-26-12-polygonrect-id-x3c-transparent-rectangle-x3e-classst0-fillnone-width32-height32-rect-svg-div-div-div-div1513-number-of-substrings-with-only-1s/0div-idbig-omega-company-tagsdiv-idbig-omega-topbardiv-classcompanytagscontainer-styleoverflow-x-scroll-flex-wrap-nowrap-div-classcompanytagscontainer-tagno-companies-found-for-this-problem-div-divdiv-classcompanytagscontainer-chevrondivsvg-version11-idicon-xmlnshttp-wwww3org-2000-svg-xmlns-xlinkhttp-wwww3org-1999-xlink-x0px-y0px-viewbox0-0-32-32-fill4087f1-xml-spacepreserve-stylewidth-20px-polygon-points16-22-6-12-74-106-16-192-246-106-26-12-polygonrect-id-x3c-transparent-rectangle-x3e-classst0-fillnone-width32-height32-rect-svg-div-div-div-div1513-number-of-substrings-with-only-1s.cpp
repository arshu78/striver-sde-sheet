class Solution {
public:
    int mod=1e9+7;
    int numSub(string s) {
        int cnt=0;
        int ans=0;
        for(auto it:s)
        {
            if(it=='1')
            {
                cnt++;
                ans+=cnt;
                ans%=mod;
            }
            else
            {
                cnt=0;
            }
           
        }
           
        
        return ans;
        
    }
};