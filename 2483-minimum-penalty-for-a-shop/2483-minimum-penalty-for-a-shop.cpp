class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        vector<int> pre(n+1,0);
        vector<int> suf(n+1,0);
        
       for(int i=1;i<=n;i++)
       {
           if(s[i-1]=='N')
           {
               pre[i]=pre[i-1] + 1;
           }
           else
           pre[i]=pre[i-1];
       }
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='Y')
            {
                suf[i] = suf[i+1] + 1;
            }
            else
            suf[i]=suf[i+1];
        }
        
        int ans=INT_MAX,ind=0;
        for(int i=0;i<=n;i++)
        {
           // cout<< pre[i]<<" "<<suf[i]<<" ";
            if(pre[i] + suf[i] <ans)
            {
               ans=pre[i] + suf[i];
                ind=i;
            }
            
        }
        
        return ind;
    }
};