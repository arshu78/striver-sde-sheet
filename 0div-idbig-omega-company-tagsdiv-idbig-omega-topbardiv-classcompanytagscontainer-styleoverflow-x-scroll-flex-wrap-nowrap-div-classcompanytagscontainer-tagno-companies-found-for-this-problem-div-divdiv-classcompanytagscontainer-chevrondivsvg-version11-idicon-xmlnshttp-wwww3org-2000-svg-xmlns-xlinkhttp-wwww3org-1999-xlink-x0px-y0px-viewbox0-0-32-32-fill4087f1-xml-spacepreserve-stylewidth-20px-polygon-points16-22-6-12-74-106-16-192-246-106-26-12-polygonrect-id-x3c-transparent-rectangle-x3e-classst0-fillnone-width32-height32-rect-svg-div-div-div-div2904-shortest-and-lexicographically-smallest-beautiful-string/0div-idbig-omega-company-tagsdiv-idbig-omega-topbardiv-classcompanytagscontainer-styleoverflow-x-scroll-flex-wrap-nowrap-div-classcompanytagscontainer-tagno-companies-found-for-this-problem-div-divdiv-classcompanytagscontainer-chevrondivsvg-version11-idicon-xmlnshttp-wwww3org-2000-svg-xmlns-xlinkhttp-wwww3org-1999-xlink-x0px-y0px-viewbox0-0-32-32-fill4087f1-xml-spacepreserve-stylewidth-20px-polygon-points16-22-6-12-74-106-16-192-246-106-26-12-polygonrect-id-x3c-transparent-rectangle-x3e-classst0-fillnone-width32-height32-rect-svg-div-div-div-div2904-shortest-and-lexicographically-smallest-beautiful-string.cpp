class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> a;
        int size=INT_MAX;
        
        for(int i=0;i<s.size();i++)
        {
            int cnt=0;
            string temp="";
            for(int j=i;j<s.size();j++)
            {
                 if(cnt<k)
                {
                    temp+=s[j];
                }
                if(s[j]=='1')
                {
                    cnt++;
                }
               
                
                if(cnt==k)
                {
                    a.push_back(temp);
                    int len=temp.size();
                    size=min(size,len);
                }
            }
        }
        
        sort(a.begin(),a.end());
        for(auto it:a)
        {
            if(it.size()==size) return it;
        }
        return "";
    }
};