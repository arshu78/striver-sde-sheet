class Solution {
public:
    bool f(int n)
    {
        if(n==1 || n==0) return false;
        
        for(int ind=1;ind<n;ind++)
        {
            if(n % ind==0)
            {
                return !f(n-ind);
            }
        }
        return false;
    }
    bool divisorGame(int n) {
        return f(n);
    }
};