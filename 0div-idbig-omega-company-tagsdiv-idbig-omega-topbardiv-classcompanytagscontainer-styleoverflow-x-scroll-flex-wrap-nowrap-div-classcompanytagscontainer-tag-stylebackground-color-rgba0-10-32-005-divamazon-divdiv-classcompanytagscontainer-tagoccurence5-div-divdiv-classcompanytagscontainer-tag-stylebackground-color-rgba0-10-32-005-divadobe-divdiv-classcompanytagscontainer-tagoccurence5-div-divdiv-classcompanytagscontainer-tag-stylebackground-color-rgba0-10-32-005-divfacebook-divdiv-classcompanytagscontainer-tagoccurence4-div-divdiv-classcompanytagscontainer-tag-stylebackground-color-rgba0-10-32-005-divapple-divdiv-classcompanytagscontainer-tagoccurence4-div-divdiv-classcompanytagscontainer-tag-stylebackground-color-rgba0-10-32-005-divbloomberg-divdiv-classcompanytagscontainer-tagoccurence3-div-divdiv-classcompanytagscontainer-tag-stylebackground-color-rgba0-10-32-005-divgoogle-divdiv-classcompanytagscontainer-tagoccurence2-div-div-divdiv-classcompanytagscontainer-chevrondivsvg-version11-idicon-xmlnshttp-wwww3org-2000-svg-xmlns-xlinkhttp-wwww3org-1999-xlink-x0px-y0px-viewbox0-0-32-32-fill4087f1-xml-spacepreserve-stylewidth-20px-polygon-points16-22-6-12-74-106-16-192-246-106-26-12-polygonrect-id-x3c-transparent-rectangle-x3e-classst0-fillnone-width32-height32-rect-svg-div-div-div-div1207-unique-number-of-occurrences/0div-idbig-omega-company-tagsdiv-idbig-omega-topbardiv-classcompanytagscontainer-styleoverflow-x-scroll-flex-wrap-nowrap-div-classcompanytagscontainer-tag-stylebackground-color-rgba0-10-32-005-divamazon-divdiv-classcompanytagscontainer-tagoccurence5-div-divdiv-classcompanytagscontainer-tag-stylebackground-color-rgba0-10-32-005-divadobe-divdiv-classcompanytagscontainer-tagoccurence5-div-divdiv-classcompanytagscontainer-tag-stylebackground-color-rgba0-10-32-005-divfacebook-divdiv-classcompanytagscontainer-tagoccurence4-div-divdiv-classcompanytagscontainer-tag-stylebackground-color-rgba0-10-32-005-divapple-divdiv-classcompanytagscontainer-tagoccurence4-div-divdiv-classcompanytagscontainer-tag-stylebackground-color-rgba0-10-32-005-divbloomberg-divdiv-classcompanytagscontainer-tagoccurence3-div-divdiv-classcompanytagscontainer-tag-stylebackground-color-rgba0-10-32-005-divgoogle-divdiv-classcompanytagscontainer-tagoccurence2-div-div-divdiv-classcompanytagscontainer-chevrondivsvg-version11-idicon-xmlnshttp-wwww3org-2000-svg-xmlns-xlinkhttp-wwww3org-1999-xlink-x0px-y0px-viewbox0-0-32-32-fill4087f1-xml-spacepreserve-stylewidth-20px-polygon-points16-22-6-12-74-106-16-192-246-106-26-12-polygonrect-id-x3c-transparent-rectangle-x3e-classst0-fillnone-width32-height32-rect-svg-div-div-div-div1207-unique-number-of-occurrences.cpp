class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(auto it:arr) mp[it]++;
        
        map<int,int> a;
        for(auto it:mp) 
        {
            if(a.find(it.second)!=a.end())
            {
                return false;
            }
            else a[it.second]++;
        }
        return true;
    }
};