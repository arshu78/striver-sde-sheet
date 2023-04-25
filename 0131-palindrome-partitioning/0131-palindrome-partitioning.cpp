class Solution {
public:
    void f(int ind,string s,vector<string>& path,vector<vector<string>>& res)
    {
        if(ind==s.size())
        {
            res.push_back(path);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(isPal(s,ind,i))
            {
                path.push_back(s.substr(ind,i-ind + 1));
                f(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    bool isPal(string s,int i,int e)
    {
        while(i<e)
        {
            if(s[i]!=s[e]) return false;
            
            i++;
            e--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        f(0,s,path,res);
        return res;
    }
};