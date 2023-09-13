class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> mp;
        int ans=0;
        for(auto it:time)
        {
            int a=it % 60;
            if(a==0) ans+=mp[0];
            else ans+=mp[60 - a];
            
            mp[a]++;
        }
        return ans;
    }
};