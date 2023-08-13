class Solution {
public:
     bool isPal(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    void f(int ind,string &str,vector<string> path,vector<vector<string>>& ans)
    {
        if(ind==str.size())
        {
            ans.push_back(path);
            return;
        }
        
        for(int i=ind;i<str.size();i++)
        {
            if(isPal(str,ind,i))
            {
                path.push_back(str.substr(ind,i-ind+1));
                f(i+1,str,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string str) {
        vector<vector<string>> res;
         vector<string> path;
        f(0,str,path,res);
        
        return res;
    }
};