class Solution {
public:
    int minOperations(string s) {
        
            int ans=0,n=s.size();
        int i=0;
             while(i<s.size())
            {
                if(i%2==0 && s[i]=='1') ans++;
                 if(i%2==1 && s[i]=='0') ans++;
                 
                 i++;
            }
        return min(ans,n-ans);
    
    }
};