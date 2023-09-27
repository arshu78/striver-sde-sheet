class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size=0;
        
        for(auto it:s)
        {
            if(isdigit(it))
            {
                size*=it - '0';
            }
            else 
            {
                size++;
            }
        }
        
        for(int i=s.size()-1;i>=0;i--)
        {
            k%=size;
            
            if(k==0 && !isdigit(s[i]))
            {
                return string(1, s[i]);
            }
            
            if(isdigit(s[i]))
            {
                size/=s[i] - '0';
            }
            else size--;
        }
        
        return "";
    }
};