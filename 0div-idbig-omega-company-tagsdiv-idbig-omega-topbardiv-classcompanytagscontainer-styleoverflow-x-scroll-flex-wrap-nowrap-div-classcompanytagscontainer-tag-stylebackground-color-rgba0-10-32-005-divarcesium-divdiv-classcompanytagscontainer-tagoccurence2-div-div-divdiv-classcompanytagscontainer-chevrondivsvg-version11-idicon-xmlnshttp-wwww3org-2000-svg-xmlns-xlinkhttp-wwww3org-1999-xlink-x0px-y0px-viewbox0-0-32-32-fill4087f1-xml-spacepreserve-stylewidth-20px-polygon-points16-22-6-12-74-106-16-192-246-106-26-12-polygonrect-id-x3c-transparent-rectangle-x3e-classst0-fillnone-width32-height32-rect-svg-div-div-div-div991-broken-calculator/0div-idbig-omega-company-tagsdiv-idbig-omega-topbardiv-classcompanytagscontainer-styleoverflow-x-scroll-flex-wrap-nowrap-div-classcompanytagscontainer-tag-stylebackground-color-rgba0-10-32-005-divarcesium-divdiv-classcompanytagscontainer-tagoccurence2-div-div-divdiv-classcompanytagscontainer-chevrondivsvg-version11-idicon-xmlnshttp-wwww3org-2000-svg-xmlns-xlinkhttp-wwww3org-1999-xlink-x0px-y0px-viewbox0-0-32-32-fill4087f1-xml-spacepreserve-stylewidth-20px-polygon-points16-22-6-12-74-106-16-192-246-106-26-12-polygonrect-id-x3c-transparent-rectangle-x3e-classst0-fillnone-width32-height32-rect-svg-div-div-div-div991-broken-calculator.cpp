class Solution {
public:
    int t;
    int f(int start,int target)
    {
        if(target<=start)
        {   
            t=target;
            return 0;
        }
        
        if(target%2==0) return 1 + f(start,target/2);
        
        return 1 + f(start,target + 1);
    }
    int brokenCalc(int start, int target) {
        
        int ans=f(start,target);
        
        return ans + (start-t);
        
    }
};