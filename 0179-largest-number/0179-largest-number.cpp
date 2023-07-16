class Solution {
public:
    static bool comp(string &a,string &b)
    {
        return (a+b) > (b+a);
    }
    string largestNumber(vector<int>& nums) {
        string ans="";
        vector<string> temp;
        for(auto it:nums) temp.push_back(to_string(it));
        
        sort(temp.begin(),temp.end(),comp);
        
        if(temp[0]=="0") return "0";
        for(auto it:temp) ans+=it;
        
        return ans;
    }
};