class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
       
        
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]++;
        }
        int i=0,j=0,ans=INT_MAX,count=mp.size();
        int st=0;
        
        while(j<s.size())
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    count--;
                }
            }
            
            if(count>0)
            {
                j++;
            }
            else if(count==0)
            {
               
                if(j-i+1<ans)
                        {
                            ans=j-i+1;
                            st=i;
                        }
                
                while(count==0)
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
                               count++;
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
                j++;
            }
        }
                       if(ans==INT_MAX){
            return "";
        }
        else{
            return s.substr(st,ans);
        }
    }
};