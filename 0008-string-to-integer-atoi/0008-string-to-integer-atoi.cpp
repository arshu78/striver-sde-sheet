class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        
        while(i<s.size() && s[i]==' ')
        {
            i++;
        }
        s=s.substr(i);
        int sign=1;
        long ans=0;
        
        i=0;
        if(s[0]=='-')
        {
            sign*=-1;
            i=1;
        }
        if(s[0]=='+')
        {
            i=1;
        }
        while(i<s.length())
        {
            if(s[i]==' ' || !isdigit(s[i])) break;
            
            ans=ans* 10 +  s[i] - '0';
            
            if(sign==-1 && ans *sign< INT_MIN) return INT_MIN;
            if(sign==1 && ans > INT_MAX) return INT_MAX;
            
            i++;
        }
        
        return (int)(sign * ans);
    }
};