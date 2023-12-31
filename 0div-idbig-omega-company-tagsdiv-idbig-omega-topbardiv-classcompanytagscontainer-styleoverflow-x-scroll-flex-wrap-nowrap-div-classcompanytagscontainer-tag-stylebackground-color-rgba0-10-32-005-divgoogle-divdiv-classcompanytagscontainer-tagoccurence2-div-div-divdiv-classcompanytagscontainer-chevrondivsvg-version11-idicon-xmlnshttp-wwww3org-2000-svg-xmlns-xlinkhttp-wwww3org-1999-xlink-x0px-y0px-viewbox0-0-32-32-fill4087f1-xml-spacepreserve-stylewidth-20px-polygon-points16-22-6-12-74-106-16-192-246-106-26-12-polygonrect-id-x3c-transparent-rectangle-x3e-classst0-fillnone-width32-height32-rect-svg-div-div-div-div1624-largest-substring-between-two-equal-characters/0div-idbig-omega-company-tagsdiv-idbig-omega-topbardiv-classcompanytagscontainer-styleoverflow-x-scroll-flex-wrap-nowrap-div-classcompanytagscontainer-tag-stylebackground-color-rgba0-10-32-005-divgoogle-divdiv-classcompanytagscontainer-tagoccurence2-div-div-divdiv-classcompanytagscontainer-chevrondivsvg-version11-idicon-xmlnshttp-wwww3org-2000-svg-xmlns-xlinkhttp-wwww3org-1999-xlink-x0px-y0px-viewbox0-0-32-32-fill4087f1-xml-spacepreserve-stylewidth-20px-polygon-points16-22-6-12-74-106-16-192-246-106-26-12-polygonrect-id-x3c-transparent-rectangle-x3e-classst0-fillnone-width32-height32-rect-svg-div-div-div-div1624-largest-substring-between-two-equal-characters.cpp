class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,int> mp;
        int maxi=-1;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                maxi=max(maxi,i-mp[s[i]]-1);
            }
            else mp[s[i]]=i;
        }
        return maxi;
    }
};