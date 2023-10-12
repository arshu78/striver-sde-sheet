class Solution {
public:
    int minDeletions(string s) {
        map<char,int> freq;
        map<int,int> mp;
        for(auto it:s)
        {
            freq[it]++;
        }
       
        
       
        int ans=0;
        for(auto it:freq)
        {
            int temp=it.second;
            while(temp > 0 && mp.find(temp)!=mp.end())
            {
                temp--;
                ans++;
            }
            mp[temp]++;
        }
        return ans;
    }
};