class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0;
        for(auto it:s) if(it=='1') ones++;
        
        string ans(s.size(),'0');
        int n=s.size();
        ans[n-1]='1';
        ones--;
        int i=0;
        while(ones--)
        {
            ans[i++]='1';
        }
        
        return ans;
    }
};