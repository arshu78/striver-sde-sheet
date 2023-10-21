class Solution {
public:
    string reformat(string s) {
        int c=0,d=0;
        vector<char> p,q;
        for(auto it:s) 
        {
           
            if(it>='0' && it<='9')
            {
                d++;
                p.push_back(it);
            }
            else
            {
                c++;
                q.push_back(it);
            }
        }
        if(abs(c-d)>1) return "";
        
        int i=0,x=0,y=0;
        string ans="";
        bool flag=true;
        
        if(c>d) flag=false;
        while(i<s.size())
        {
            if(flag) 
            {
                flag=false;
                ans+=p[x++];
            }
            else
            {
                flag=true;
                ans+=q[y++];
            }
            
            i++;
        }
        return ans;
        
    }
};