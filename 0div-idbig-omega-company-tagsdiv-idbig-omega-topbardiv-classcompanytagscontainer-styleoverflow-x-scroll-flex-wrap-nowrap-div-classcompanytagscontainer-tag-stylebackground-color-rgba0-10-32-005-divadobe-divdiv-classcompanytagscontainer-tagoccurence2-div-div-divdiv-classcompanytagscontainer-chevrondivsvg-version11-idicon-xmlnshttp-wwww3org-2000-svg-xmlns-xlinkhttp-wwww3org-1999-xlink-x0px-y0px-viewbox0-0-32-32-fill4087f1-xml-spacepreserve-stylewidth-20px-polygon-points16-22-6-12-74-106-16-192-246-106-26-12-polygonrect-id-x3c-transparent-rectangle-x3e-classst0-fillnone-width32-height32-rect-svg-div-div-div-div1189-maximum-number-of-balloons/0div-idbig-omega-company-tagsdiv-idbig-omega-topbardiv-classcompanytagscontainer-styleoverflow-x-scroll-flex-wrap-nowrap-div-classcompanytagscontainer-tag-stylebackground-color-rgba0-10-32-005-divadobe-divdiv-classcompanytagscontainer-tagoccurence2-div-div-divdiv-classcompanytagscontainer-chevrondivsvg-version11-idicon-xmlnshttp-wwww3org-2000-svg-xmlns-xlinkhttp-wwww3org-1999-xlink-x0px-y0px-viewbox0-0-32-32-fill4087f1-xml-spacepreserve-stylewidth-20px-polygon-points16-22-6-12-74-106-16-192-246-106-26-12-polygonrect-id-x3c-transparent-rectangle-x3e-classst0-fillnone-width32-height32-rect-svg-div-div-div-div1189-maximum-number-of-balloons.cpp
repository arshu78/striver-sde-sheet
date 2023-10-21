class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        string s="balloon";
        for(auto it:text) mp[it]++;
        int ans=0;
        while(!mp.empty())
        {
            bool f=true;
            for(auto it:s)
            {
                mp[it]--;
                if(mp[it]<0)
                {
                    f=false;
                    break;
                }
            }
            if(f) ans++;
            else break;
        }
        return ans;
    }
};