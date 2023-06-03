class Solution {
public:
    string defangIPaddr(string address) {
        string ans="";
        string temp="[.]";
        
        for(auto it:address)
        {
            if(it=='.')
            {
                ans+=temp;
            }
            else
            {
                ans.push_back(it);
            }
        }
        return ans;
    }
};