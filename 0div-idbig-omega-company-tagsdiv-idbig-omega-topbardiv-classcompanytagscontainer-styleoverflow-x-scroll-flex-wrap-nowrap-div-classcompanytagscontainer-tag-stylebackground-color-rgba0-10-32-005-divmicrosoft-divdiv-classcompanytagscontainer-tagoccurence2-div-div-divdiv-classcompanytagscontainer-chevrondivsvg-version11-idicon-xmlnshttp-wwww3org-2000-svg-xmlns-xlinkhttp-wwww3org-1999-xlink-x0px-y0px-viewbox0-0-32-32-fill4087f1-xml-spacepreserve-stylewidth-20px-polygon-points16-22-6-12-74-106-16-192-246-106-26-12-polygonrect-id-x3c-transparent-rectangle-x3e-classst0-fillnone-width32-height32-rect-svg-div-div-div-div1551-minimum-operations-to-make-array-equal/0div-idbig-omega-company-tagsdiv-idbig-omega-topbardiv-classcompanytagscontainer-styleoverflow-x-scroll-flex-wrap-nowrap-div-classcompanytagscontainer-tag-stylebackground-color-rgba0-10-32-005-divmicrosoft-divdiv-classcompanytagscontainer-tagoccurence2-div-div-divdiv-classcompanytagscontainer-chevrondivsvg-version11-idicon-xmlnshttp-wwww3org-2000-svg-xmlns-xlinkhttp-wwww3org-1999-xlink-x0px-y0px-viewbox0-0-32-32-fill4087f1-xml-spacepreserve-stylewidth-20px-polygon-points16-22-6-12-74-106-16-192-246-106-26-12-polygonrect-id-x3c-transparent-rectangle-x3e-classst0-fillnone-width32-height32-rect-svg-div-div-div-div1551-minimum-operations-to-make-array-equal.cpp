class Solution {
public:
    int minOperations(int n) {
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=2 * i +1;
        }
        int ans=0;
        for(int i=0;i<n/2;i++)
        {
           
                ans+=n - (2*i+1);
            
           
        }
        return ans;
    }
};