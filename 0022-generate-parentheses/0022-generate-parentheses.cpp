class Solution {
public:
    void f(int i,int j,string t,vector<string>& ans)
    {
        if(i==0 && j==0) 
        {
            ans.push_back(t);
            return;
        }
        
        if(j>0) f(i,j-1,t+")",ans);
        if(i>0) f(i-1,j+1,t+"(",ans); //if we add one opening bracket then its corresponding closeing size was increased
        
    }
    vector<string> generateParenthesis(int n) {

        
        vector<string> ans;
        string temp="";
        f(n,0,temp,ans);
        return ans;
    }
};