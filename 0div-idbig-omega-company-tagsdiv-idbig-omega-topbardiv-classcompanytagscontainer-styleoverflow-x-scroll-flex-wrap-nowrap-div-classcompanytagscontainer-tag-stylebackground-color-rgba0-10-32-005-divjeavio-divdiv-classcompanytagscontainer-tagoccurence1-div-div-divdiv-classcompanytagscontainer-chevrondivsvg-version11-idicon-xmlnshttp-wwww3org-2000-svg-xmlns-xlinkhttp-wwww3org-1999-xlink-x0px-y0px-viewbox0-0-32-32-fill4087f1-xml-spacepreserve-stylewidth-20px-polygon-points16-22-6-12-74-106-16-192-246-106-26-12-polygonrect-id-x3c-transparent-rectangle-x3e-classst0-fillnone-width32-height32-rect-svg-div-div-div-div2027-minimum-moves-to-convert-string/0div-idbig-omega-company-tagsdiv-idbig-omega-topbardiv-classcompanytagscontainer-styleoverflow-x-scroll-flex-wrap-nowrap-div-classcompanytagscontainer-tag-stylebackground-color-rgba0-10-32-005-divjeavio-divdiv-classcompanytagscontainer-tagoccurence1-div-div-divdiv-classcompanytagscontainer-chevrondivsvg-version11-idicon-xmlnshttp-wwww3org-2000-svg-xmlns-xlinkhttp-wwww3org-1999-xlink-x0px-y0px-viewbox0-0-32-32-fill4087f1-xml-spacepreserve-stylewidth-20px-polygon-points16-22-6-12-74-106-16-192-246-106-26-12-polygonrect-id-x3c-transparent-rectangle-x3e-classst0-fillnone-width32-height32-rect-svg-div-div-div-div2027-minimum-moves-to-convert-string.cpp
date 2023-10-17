class Solution {
public:
    int minimumMoves(string s) {
        int i=0,ans=0;
        while(i<s.size())
        {
            if(s[i]=='O') i++;
            else
            {
                ans++;
                i+=3;
            }
        }
        return ans;
    }
};