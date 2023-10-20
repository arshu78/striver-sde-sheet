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
       if(s.size()==0 || k>s.size()) return 0;
        if(k==0) return s.size();
        
        unordered_map<char,int> mp;
        for(auto it:s) mp[it]++;
        int cnt=0;
        for(auto it:s)
        {
            if(mp[it]>=k) cnt++;
            else break;
        }
        
        if(cnt==s.size()) return s.size();
        
        int left=longestSubstring(s.substr(0,cnt),k);
        int right=longestSubstring(s.substr(cnt+1),k);
        
        return max(left,right);
    }
};