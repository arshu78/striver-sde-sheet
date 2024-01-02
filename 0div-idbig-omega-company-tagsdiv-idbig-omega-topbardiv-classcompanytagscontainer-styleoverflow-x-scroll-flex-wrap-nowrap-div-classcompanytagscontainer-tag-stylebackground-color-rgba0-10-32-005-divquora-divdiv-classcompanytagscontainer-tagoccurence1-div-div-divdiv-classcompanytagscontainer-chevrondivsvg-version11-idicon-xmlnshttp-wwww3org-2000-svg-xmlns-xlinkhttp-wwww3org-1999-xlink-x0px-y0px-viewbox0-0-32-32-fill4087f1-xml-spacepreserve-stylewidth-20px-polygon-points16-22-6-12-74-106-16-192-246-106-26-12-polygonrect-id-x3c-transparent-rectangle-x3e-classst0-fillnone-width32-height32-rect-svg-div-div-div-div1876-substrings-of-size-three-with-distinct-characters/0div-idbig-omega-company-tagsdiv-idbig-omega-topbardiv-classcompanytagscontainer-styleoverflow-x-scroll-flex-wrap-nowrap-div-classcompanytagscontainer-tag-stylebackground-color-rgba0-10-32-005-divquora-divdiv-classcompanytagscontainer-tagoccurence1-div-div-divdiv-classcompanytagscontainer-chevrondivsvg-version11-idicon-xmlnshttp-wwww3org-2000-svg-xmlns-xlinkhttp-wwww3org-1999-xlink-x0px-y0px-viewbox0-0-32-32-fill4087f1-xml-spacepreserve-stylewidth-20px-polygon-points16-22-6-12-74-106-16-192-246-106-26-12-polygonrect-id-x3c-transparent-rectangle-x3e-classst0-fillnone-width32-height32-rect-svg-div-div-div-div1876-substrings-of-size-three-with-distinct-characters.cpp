class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size()<3) return 0;
        int ans=0;
        for(int i=0;i<s.size()-2;i++)
        {
            map<char,int> mp;
            bool f=true;
            for(int j=i;j<i+3;j++)
            {
                if(mp.find(s[j])!=mp.end()) 
                {
                    f=false;
                    break;
                }
                else mp[s[j]]++;
            }
            if(f) ans++; 
        }
        return ans;
    }
};