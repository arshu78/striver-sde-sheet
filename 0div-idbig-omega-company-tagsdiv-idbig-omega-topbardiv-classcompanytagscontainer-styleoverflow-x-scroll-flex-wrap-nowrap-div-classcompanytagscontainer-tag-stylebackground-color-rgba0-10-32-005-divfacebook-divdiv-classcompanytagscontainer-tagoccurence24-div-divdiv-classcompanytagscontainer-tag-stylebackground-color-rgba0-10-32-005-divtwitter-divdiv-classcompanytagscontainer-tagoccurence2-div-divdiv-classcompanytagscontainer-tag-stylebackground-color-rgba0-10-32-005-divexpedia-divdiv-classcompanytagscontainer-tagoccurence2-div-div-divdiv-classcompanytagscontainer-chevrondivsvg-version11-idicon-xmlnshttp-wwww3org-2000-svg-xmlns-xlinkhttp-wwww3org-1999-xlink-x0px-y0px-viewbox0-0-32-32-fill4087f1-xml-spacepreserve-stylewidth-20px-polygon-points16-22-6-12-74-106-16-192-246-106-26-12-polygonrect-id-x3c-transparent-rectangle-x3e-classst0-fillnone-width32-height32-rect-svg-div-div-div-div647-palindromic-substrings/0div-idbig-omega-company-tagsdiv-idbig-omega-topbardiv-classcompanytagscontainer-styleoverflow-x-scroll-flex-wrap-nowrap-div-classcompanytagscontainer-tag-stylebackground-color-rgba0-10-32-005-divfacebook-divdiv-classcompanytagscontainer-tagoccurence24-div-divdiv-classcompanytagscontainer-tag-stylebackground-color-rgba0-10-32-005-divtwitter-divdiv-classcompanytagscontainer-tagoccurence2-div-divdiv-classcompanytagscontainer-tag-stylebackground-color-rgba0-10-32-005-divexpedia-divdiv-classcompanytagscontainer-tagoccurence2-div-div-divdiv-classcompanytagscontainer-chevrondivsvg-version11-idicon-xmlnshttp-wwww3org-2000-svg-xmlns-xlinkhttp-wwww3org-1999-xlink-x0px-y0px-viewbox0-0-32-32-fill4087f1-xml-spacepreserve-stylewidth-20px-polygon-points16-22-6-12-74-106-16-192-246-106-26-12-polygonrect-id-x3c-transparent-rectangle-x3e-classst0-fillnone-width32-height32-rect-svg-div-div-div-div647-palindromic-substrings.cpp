class Solution {
public:
    int check(string s,int i,int j)
    {
       int cnt=0;
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
  
    int countSubstrings(string s) {
        
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            int e=check(s,i,i+1);
            int o=check(s,i-1,i+1);
            
            ans+=e + o+1;
        }
        return ans;
    }
};