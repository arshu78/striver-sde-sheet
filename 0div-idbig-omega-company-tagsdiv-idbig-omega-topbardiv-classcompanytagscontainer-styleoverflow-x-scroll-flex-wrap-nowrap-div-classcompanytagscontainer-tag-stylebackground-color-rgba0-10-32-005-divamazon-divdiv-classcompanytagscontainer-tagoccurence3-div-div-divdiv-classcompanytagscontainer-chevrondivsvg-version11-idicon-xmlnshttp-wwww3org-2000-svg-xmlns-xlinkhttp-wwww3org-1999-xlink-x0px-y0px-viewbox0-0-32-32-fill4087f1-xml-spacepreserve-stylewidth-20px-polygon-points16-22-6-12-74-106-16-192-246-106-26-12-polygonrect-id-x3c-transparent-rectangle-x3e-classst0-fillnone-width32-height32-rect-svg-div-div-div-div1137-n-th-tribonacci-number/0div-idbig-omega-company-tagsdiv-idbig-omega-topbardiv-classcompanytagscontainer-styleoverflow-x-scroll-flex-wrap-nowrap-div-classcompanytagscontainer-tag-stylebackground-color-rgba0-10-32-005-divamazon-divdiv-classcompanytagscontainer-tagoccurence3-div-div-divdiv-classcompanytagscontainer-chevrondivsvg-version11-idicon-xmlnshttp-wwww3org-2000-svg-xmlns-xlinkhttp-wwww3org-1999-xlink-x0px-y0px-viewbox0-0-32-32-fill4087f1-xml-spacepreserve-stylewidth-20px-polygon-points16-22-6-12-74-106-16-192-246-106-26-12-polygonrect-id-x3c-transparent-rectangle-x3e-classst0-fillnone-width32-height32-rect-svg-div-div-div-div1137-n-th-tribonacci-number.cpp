class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<3) return 1;
        long long int a=0,b=1,c=1;
        
        for(int i=3;i<=n;i++)
        {
            long long int s=a + b + c;
             a=b;
            b=c;
            c=s;
            
        }
        return c;
    }
};