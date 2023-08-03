class Solution {
public:
    void solve(string digits,string out,int ind,string mp[],vector<string>& ans)
    {
        if(ind>=digits.length())
        {
            ans.push_back(out);
            return;
        }
        
        int d=digits[ind] - '0';
        string value=mp[d];
        
        for(int i=0;i<value.size();i++)
        {
            out.push_back(value[i]);
            solve(digits,out,ind+1,mp,ans);
            out.pop_back();
        }
            
    }
    vector<string> letterCombinations(string digits) {
       vector<string> ans;
        if(digits.size()==0) return ans;
        string output;
        string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        solve(digits,output,index,mp,ans);
        return ans;
    }
};