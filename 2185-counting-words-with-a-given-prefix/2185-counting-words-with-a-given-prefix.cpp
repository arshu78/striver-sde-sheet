class Solution {
public:
    bool check(string& org,string& p)
    {
        string ans="";
        for(auto it:org)
        {
            ans+=it;
            if(ans==p) return true;
        }
        if(ans==p) return true;
        
        return false;
    }
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(auto it:words)
        {
            if(check(it,pref)) cnt++;
        }
        return cnt;
    }
};