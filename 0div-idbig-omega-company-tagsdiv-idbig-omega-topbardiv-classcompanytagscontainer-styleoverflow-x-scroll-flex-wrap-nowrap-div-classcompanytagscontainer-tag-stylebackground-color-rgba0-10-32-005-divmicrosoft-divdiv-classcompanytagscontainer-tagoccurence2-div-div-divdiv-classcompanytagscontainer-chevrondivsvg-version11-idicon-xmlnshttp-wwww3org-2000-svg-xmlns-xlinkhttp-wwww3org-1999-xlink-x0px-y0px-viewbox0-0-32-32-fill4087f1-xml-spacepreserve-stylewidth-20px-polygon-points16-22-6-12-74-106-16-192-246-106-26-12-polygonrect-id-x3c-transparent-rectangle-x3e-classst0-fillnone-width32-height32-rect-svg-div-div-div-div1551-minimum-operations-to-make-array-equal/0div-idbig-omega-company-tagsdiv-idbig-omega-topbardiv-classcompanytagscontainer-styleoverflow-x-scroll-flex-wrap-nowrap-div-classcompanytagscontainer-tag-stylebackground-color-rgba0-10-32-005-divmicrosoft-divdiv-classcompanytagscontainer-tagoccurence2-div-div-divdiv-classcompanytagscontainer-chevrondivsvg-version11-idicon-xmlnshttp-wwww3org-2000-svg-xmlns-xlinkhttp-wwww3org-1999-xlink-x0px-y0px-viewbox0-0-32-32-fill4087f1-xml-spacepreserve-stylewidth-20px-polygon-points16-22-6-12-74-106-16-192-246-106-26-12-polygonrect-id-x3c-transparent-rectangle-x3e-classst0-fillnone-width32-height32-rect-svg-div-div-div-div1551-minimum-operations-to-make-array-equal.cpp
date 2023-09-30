class Solution {
public:
    int minOperations(int n) {
        int val;
        if(n%2!=0)
        {
            int mid=n/2;
            val=2 * mid+1;
        }
        else 
        {
            int mid=n/2;
            val=2*mid + 1;
            mid--;
            val+=2*mid+1;
            val/=2;
        }
        
        int ans=0;
        for(int i=0;i<n/2;i++)
        {
            ans+=val - (2*i+1);
        }
        return ans;
    }
};