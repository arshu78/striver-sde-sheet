class Solution {
public:
    string reversePrefix(string s, char ch) {
        int i=0;
        while(i<s.length())
        {
            if(s[i]==ch) break;
            i++;
        }
        
        if(i==s.length()) return s;
        
        reverse(s.begin(),s.begin()+i+1);
        
        return s;
        
    }
};