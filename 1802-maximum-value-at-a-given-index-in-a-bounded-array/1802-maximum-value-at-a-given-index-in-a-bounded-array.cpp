class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long low=1,high=maxSum,ans=0;;
        long r=n-index-1,l=index;
        while(low<=high)
        {
            long mid=(low+high)>>1;
            long ls=0;
            long rs=0;
            long m=mid-1;
            long sum=mid;
            if(r<=m)
            {
                rs=m*(m+1) /2 - (m-r) * (m-r+1)/2;
            }
            else
            {
                rs=m*(m+1)/2 + (r-m);  // add remainings ones
            }
            
             if(l<=m)
            {
                ls=m*(m+1) /2 - (m-l)* (m-l+1)/2;
            }
            else
            {
                ls=m*(m+1)/2 + (l-m);  // add remainings ones
            }
            
            sum+= ls + rs;
            if(sum<=maxSum)
            {
                ans=mid;
                low=mid+1; 
            }
            else{
                high=mid-1;
            }
        }
        
        return ans;
    }
};