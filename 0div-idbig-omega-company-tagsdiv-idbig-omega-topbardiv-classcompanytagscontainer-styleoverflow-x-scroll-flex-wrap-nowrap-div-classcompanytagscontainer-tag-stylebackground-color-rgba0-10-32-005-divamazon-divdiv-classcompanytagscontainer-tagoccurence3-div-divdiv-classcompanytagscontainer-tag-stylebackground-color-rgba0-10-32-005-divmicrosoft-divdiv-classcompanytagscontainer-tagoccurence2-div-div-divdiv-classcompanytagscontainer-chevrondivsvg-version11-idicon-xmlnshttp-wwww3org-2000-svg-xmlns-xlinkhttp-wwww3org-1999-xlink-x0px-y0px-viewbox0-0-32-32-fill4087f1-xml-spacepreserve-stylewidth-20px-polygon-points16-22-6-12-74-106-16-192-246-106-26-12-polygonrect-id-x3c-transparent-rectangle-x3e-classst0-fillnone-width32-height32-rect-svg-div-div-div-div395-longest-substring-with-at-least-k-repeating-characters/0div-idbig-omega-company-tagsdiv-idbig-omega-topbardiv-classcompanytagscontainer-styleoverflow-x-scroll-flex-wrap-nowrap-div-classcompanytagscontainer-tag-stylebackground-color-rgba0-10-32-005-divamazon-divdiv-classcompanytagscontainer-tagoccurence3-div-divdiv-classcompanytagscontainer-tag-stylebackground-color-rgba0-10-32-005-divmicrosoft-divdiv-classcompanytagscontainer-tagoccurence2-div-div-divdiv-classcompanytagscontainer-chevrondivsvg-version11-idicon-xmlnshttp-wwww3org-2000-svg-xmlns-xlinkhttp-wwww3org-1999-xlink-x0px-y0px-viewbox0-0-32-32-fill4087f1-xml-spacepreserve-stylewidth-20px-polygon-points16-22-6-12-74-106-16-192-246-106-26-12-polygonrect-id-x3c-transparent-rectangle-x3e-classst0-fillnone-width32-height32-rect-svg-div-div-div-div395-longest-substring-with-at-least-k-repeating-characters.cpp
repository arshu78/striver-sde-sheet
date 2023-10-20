class Solution {
public:
    
    bool check(vector<int>& v,int k)
    {
        for(int i=0;i<26;i++)
        {
            if(v[i]!=0 && v[i]<k) return false;
        }
        return true;
    }
    int longestSubstring(string s, int k) {   
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            vector<int> v(26,0);
            for(int j=i;j<s.length();j++)
            {
                v[s[j] - 'a']++;
               if(check(v,k))
               {
                   ans=max(ans,j-i+1);
               }
            }
          
        }
        return ans;
    }
};