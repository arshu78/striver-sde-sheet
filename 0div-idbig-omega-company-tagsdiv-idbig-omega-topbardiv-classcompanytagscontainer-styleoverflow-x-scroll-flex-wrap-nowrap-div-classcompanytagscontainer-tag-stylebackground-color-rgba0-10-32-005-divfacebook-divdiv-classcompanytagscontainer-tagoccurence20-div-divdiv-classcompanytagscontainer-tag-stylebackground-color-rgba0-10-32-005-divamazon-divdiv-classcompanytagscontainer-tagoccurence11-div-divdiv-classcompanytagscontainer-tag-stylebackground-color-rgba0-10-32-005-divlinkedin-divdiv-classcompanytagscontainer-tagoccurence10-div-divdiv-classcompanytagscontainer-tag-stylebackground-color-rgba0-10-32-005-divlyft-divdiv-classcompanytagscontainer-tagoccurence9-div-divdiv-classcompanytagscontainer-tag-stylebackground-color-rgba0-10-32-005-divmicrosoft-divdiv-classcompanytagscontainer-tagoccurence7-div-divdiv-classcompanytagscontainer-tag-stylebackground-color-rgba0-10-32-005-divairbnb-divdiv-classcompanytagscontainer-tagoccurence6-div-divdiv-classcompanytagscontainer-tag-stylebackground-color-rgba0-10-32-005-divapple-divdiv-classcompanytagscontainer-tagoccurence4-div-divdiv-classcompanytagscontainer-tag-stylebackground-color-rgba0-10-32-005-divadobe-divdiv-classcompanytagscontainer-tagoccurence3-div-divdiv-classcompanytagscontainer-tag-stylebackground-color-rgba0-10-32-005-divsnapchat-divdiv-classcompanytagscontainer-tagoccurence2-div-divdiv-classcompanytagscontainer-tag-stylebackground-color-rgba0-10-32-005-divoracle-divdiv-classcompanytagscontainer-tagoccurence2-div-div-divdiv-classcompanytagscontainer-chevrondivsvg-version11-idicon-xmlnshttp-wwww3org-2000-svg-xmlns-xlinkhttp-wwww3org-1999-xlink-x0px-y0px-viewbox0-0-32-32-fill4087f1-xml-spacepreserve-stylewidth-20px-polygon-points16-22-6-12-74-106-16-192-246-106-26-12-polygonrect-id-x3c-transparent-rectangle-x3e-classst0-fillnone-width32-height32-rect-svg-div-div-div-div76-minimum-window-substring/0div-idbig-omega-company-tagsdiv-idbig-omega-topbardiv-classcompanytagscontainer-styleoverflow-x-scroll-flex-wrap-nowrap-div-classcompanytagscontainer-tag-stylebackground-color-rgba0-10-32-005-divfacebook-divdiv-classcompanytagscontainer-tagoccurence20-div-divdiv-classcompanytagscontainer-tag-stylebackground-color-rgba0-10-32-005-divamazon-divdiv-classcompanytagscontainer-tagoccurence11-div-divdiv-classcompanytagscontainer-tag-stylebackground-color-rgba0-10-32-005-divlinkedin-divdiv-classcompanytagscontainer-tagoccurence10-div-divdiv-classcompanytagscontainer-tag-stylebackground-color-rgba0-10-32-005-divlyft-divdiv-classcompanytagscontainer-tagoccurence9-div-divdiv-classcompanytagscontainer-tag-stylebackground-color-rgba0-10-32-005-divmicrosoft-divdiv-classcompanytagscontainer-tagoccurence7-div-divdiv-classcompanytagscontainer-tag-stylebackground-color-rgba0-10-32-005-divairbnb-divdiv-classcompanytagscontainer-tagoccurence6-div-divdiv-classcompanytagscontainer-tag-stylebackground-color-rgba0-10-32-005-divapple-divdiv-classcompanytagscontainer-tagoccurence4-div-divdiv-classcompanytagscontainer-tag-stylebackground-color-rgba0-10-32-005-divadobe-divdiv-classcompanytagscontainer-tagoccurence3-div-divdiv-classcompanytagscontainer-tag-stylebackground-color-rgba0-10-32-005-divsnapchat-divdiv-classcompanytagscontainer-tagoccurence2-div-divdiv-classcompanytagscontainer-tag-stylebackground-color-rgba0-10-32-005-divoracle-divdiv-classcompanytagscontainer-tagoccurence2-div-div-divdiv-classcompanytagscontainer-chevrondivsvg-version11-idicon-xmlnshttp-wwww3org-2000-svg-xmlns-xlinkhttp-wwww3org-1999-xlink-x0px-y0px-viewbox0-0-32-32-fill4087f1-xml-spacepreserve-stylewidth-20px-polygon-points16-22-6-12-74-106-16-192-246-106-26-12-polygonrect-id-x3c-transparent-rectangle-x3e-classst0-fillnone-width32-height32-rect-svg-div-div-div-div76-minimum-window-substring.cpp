class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        for(auto it:t) mp[it]++;
        
        int i=0,j=0;
        int ans=INT_MAX,st=-1,cnt=mp.size();
        while(j<s.size())
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                cnt--;
            }
            
            if(cnt>0)
            {
                j++;
            }
            else if(cnt==0)
            { if(j-i+1<ans)
                        {
                            ans=j-i+1;
                            st=i;
                        }
                
                while(cnt==0)
                {
                    if(mp.find(s[i])==mp.end())
                       {
                           i++;
                           
                        if(j-i+1<ans)
                        {
                            ans=j-i+1;
                            st=i;
                        }
                       }
                       else
                       {
                           mp[s[i]]++;
                           if(mp[s[i]]>0)
                           {
                               i++;
                               cnt++;
                           }
                           else
                           {
                                 i++;
                                if(j-i+1<ans)
                                     {
                                            ans=j-i+1;
                                            st=i;
                                    }
                           }
                       }
                }      
                j++;}
            }
        
        if(ans==INT_MAX) return "";
        
        return s.substr(st,ans);
    }
};