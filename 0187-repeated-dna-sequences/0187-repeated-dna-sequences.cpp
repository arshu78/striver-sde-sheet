class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        vector<string> ans;
        if(s.size()<10) return {};
        string t="";
        for(int i=0;i<10;i++)
        {
            t+=s[i];
        }
        mp[t]++;
        for(int i=10;i<s.size();i++)
        {
            t.erase(t.begin());
            t+=s[i];
            mp[t]++;
        }
        
        for(auto it:mp) if(it.second>1) ans.push_back(it.first);
        
        return ans;
        
    }
    
};