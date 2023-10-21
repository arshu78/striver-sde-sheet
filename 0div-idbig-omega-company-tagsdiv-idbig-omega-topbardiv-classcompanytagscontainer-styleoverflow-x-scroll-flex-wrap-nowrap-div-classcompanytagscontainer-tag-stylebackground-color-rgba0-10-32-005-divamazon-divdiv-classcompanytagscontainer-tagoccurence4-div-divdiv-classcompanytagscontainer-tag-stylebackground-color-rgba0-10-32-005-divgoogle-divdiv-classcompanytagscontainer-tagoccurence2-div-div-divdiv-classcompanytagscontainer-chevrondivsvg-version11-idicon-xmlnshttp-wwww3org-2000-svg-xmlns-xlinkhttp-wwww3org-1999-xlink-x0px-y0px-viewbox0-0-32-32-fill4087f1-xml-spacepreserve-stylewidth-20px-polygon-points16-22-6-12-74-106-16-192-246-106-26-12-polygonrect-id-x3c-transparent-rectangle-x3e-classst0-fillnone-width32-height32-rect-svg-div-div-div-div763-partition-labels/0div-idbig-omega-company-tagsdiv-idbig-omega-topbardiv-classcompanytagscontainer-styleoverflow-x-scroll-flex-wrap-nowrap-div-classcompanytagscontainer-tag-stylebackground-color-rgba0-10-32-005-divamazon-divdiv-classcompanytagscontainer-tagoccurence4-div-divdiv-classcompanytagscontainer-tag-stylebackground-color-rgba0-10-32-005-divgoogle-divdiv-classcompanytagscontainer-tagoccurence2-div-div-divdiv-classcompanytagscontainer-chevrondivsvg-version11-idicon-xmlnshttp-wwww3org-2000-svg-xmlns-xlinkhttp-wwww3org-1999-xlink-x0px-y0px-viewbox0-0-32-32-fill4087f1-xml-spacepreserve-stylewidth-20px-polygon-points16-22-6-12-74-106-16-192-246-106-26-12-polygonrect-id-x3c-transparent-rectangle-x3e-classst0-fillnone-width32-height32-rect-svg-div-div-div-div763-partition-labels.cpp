class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        unordered_map<char,int> c;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(mp.find(s[i])==mp.end()) mp[s[i]]=i;
        }
        
        int last=0;
        int j=0,i;
        vector<int> ans;
        for(i=0;i<s.length();i++)
        {
            if(c.find(s[i])==c.end())
            {
                if(last==0)
                {
                    if(i!=0)
                    {
                        ans.push_back(i-j);
                    }
                    j=i;
                }
                last++;
            }
            
            if(mp[s[i]]==i) last--;
            
            c[s[i]]++;
        }
        
        if(last==0)
        {
            ans.push_back(i-j);
        }
        return ans;
    }
};