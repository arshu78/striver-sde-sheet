class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ind=-1;
        int cnt=0;
        if(ruleKey=="type") ind=0;
        else if(ruleKey=="color") ind=1;
        else ind=2;
        
        for(auto it:items)
        {
            if(ind<it.size() && it[ind]==ruleValue) cnt++;
        }
        return cnt;
    }
};