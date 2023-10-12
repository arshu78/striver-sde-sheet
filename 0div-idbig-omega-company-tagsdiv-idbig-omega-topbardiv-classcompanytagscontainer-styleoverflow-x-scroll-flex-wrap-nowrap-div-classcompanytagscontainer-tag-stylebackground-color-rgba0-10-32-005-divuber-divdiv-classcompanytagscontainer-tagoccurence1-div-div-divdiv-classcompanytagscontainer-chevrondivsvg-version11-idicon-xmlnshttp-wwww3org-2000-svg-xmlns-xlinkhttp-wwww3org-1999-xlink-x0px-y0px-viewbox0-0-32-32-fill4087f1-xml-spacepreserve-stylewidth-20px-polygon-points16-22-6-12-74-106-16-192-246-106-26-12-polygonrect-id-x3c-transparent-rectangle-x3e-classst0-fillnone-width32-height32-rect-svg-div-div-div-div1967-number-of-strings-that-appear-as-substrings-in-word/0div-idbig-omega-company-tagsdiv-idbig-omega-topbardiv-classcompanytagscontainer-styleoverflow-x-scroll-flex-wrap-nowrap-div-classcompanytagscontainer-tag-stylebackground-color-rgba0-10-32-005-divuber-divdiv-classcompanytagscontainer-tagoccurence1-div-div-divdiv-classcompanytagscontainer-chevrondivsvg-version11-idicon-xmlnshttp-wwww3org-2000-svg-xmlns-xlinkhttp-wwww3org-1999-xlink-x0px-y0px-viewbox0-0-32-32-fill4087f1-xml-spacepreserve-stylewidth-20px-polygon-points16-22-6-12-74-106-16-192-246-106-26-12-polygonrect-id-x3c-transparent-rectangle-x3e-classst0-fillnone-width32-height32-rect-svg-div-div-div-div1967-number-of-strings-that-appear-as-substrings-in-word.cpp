class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int> mp;
        for(auto it:patterns) mp[it]++;
        int ans=0;
        for(int i=0;i<word.size();i++)
        {
            string temp="";
           
            for(int j=i;j<word.size();j++)
            {
                temp+=word[j];
                if(mp.find(temp)!=mp.end())
                {
                    ans+=mp[temp];
                    mp.erase(temp);
                }
            }
            
        }
        return ans;
    }
};