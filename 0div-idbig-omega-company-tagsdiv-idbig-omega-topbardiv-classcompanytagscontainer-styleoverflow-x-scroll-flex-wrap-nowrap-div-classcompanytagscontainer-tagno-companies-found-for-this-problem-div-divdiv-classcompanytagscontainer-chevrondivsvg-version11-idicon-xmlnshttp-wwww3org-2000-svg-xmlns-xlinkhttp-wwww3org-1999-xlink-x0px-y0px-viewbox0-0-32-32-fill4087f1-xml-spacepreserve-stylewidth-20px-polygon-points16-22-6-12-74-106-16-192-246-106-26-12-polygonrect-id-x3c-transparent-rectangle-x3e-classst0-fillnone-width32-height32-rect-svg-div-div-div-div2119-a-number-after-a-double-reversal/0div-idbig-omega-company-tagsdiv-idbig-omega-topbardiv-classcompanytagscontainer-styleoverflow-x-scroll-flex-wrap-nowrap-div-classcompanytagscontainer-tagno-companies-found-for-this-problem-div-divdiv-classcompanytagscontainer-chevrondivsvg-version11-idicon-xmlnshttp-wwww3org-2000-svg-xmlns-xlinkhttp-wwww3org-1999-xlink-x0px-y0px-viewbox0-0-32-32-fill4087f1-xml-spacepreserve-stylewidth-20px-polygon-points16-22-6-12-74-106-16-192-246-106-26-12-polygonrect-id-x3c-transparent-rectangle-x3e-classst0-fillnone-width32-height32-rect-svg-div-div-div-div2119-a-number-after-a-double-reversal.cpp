class Solution {
public:
    bool isSameAfterReversals(int num) {
        string s=to_string(num);
        int n=s.length();
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='0')
            i++;
            else break;
        }
        
        return i==n || s[n-1]!='0';
    }
};