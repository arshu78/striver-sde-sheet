class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        int a=s.length()-1;
        while(s[a]==' ') a--;
        for(int i=a;i>=0;i--)
        {
            if(s[i]==' ') break;
            
            cnt++;
        }
        return cnt;
    }
};