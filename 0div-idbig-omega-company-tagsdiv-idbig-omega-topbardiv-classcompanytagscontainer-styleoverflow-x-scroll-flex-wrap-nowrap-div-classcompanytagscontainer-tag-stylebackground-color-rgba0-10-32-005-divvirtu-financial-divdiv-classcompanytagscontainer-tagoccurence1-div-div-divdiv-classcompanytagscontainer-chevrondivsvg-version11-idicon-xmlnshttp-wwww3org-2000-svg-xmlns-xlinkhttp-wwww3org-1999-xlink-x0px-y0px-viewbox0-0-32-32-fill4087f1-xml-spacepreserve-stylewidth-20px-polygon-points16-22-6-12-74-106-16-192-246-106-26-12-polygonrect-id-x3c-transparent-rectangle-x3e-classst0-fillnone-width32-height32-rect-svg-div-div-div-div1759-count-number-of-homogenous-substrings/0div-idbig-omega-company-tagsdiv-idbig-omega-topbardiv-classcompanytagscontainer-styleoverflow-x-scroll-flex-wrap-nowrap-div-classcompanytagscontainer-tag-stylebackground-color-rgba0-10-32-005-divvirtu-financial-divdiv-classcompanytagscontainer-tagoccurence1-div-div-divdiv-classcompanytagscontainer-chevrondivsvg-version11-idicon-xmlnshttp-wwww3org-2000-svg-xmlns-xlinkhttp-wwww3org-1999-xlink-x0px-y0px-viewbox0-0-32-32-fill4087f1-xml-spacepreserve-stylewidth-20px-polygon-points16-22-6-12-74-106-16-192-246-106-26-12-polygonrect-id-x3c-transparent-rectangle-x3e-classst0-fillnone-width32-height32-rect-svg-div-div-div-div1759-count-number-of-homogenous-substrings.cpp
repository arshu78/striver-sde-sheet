class Solution {
public:
    int mod=1e9 + 7;
    int countHomogenous(string s) {
       int ans=0,i,j;
        for(i=0;i<s.size();i++)
        {
            
            for(j=i;j<s.size();j++)
            {
                if(s[i]==s[j])
                {
                     ans=(ans+(j-i+1))% mod ;
                }
                else break;
            }
            i=j-1;
            
        }
       return ans % mod;
    }
};