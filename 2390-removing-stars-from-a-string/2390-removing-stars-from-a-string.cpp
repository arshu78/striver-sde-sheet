class Solution {
public:
    string removeStars(string s) {
        string ans="";
        int cnt=0;
      for(int i=s.length()-1;i>=0;i--)
      {
          char c=s[i];
          if(c=='*') 
          {
              cnt++;
              continue;
          }
          if(cnt==0 && c!='*') ans.push_back(c);
          else
          {
              cnt--;
          }
      }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};