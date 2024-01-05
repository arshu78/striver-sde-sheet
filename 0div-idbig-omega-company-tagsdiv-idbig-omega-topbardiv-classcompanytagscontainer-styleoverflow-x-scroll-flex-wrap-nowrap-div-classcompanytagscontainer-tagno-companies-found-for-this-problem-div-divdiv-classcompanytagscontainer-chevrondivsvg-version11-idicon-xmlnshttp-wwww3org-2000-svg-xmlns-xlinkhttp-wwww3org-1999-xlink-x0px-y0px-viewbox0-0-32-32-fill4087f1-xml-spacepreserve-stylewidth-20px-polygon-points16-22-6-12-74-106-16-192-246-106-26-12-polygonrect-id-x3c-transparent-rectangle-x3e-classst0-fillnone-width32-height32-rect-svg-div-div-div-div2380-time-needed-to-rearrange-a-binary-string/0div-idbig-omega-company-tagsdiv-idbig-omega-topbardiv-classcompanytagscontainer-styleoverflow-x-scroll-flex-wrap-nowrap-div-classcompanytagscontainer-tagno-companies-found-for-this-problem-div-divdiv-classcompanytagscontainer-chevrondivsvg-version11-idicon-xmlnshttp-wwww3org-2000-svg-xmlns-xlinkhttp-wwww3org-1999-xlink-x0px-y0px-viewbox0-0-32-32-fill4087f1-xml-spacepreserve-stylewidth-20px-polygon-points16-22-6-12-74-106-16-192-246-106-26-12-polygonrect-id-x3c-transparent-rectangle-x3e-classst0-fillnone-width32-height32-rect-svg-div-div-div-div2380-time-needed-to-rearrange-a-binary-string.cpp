class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int ans=0;
        while(1)
        {
            bool flag=true;
            int i=1;
           while(i<s.size())
            {
                if(s[i]=='1' && s[i-1]=='0')
                {
                    s[i]='0';
                    s[i-1]='1';
                    flag=false;
                    i+=2;
                }
                else i++;
            }
            if(flag) break;
            else ans++;
        }
       // cout<<s;
        return ans;
    }
};