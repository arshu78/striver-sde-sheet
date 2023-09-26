class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> mp;
        map<char,bool> vis;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            vis[s[i]]=false;
        }
        string ans="";
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]--;
            if(vis[s[i]]) continue;
            while(!ans.empty() && s[i]< ans.back() && mp[ans.back()]>0)
            {
                vis[ans.back()]=false;
                ans.pop_back();
                
            }
                ans+=s[i];
                vis[s[i]]=true;
         
        }
        
        return ans;
    }
    
};