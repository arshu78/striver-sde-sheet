class Solution {
public:
    string shiftingLetters(string a, vector<int>& s) {
        int n=s.size();
       
        s[n-1]=s[n-1] % 26;
        for(int i=s.size()-2;i>=0;i--)
        {
            s[i]=(s[i] + s[i+1]) % 26;
        }
        
        for(int i=0;i<a.size();i++)
        {
            a[i]=(((a[i] - 'a') + s[i]) % 26 ) + 'a';
        }
        return a;
    }
};