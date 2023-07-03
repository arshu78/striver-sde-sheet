class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        if(s==goal)
        {
            set<char> c;
            for(auto it:s) c.insert(it);
            if(c.size() < s.length()) return true;
        }
        vector<int> cnt;
        int i=0;
        while(i<s.length())
        {
            if(s[i]!=goal[i]) cnt.push_back(i);
            i++;
        }
        return cnt.size()==2 && s[cnt[0]]==goal[cnt[1]] && s[cnt[1]]==goal[cnt[0]];
    }
};