class Solution {
public:
    int partitionString(string s) {
        map<char,int> mp;
        int j=0,cnt=1;
        while(j<s.length())
        {
         if(mp.find(s[j])==mp.end())
         {
             mp[s[j]]++;
                j++;
         }
            else
            {
                cnt++;
                mp.clear();
            }
            
        }
        return cnt;
    }
};