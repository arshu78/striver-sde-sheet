class Solution {
public:
    
    bool f(string s1,string s2)
    {
        int k=0;
        
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]==s2[k]) k++;
            
            if(k==s2.size()) return true;
        }
        
        return k==s2.length();
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        map<string,int> mp;
        
        for(auto it:words)
        {
            mp[it]++;
        }
        
        int cnt=0;
        for(auto it:mp)
        {
            if(f(s,it.first)) cnt+=it.second;
        }
        
        return cnt;
     
    }
};