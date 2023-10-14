class Solution {
public:
    int f(string s)
    {
        int i=0,a=0,b=0;
            for(i=0;i<s.size();i++)
            {
                if(s[i]!=':')
                {
                    a=a * 10 + (s[i] - '0');
                }
                else{
                    break;
                }
            }
            
            while(i<s.size())
            {
                b=b * 10 + (s[i] - '0');
                i++;
            }
            
            a=a*60;
            a+=b;
        return a;
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int a=0,b=0,p=0,q=0;
        
        a= f(event1[0]);
        b= f(event1[1]);
        p= f(event2[0]);
        q= f(event2[1]);
        // cout<<a <<" "<<b<<endl;
        // cout<<p <<" "<<q<<endl;
        
       if(q>=a && p<=b) return true;
        return false;
       
         
            
            
        
    }
};