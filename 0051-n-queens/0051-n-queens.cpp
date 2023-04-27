class Solution {
public:
    bool check(int r,int c,vector<string> b,int n)
    {
        int dr=r;
        int dc=c;
        while(r>=0 && c>=0)
        {
            if(b[r][c]=='Q') return false;
            r--;
            c--;
        }
        r=dr;
        c=dc;
        while(c>=0)
        {
           if(b[r][c]=='Q') return false;
            c--;
        }
         r=dr;
        c=dc;
        while(r<n && c>=0)
        {
            if(b[r][c]=='Q') return false;
            r++;
            c--;
        }
        return true;
    }
    void f(int ind,vector<string> b,vector<vector<string>>& ans,int n)
    {
        if(ind==n) 
        {
            ans.push_back(b);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(check(i,ind,b,n))
            {
                b[i][ind]='Q';
                f(ind+1,b,ans,n);
                b[i][ind]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> b(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            b[i]=s;
        }
        f(0,b,ans,n);
        return ans;
    }
};