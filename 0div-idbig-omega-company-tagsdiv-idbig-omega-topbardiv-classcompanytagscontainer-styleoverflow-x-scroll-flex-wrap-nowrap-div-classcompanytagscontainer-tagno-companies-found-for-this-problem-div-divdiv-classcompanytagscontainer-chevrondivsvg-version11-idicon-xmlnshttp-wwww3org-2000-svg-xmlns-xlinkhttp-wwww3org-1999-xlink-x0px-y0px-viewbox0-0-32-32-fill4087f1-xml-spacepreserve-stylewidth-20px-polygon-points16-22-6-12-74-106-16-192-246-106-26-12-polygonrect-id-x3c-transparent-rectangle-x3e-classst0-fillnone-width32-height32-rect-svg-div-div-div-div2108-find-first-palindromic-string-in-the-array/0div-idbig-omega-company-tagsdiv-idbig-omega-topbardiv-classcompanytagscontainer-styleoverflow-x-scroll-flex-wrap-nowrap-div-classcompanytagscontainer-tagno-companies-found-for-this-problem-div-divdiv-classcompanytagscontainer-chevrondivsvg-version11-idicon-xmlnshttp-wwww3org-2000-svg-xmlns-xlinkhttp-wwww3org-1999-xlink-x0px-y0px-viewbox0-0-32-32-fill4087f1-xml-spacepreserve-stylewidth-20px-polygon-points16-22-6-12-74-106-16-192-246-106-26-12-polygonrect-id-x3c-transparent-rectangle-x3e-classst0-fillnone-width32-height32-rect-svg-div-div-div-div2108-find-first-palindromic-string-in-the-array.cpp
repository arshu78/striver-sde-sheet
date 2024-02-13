class Solution {
public:
    bool f(string &st)
    {
        int n=st.size();
        for(int i=0;i<n/2;i++)
        {
            if(st[i]!=st[(n-1)-i]) return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto it:words)
        {
            if(f(it)) return it;
        }
        return "";
    }
};