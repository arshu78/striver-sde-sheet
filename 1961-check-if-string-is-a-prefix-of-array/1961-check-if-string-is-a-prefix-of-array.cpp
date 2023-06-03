class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string ans="";
        for(auto it:words)
        {
            ans+=it;
            if(ans==s) return true;
        }
        
        if(ans==s) return true;
        
        return false;
    }
};