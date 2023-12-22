class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        left[0]=(s[0]=='0');
        right[n-1]=(s[n-1]=='1');
        
        
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
               {
                   left[i]=left[i-1] + 1;
                
               }
               else left[i]=left[i-1];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='1')
            {
                right[i]=right[i+1] + 1;
               
            }
            else right[i]=right[i+1];
         }
               
        int maxi=0;
               for(int i=0;i<n-1;i++)
               {
                   maxi=max(maxi,left[i]+right[i+1]);
               }
               
       
               return maxi;
               
    
    }
};