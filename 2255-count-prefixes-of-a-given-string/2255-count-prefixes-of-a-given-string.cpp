class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        string temp="";
        int cnt=0;
        for(auto it: s)
        {
            temp+=it;
            for(auto j:words)
            {
                if(j==temp)
                {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};