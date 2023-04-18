class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i=0,j=0,cnt=0;
        while(i<word1.length() && j<word2.length())
        {
            if(cnt % 2==0)
            {
                ans+=word1[i++];
            }
            else
            {
                ans+=word2[j++];
            }
            cnt++;
        }
        while(i<word1.length())
        {
                ans+=word1[i++];   
        }
          while(j<word2.length())
        {
                ans+=word2[j++];   
        }
        return ans;
    }
};