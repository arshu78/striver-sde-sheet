class Solution {
public:
    int solve(int n)
    {
        int ans=0;
        while(n)
        {
            int dig=n%10;
            ans+=(dig*dig);
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
       
        int slow=n;
        int fast=solve(n);
        
        while(fast!=1 && fast!=slow)
        {
            slow=solve(slow);
            fast=solve(solve(fast));
        }
        
       return fast==1;
        
    }
};