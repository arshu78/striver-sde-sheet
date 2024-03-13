class Solution {
public:
    int pivotInteger(int n) {
        vector<int> left(n,0),right(n,0);
        left[0]=1;
        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1] + i+1;
        }
        
        right[n-1]=n;
         for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1] + i+1;
        }
        
        for(int i=0;i<n;i++)
        {
            if(left[i]==right[i]) return i+1;
        }
        return -1;
    }
};