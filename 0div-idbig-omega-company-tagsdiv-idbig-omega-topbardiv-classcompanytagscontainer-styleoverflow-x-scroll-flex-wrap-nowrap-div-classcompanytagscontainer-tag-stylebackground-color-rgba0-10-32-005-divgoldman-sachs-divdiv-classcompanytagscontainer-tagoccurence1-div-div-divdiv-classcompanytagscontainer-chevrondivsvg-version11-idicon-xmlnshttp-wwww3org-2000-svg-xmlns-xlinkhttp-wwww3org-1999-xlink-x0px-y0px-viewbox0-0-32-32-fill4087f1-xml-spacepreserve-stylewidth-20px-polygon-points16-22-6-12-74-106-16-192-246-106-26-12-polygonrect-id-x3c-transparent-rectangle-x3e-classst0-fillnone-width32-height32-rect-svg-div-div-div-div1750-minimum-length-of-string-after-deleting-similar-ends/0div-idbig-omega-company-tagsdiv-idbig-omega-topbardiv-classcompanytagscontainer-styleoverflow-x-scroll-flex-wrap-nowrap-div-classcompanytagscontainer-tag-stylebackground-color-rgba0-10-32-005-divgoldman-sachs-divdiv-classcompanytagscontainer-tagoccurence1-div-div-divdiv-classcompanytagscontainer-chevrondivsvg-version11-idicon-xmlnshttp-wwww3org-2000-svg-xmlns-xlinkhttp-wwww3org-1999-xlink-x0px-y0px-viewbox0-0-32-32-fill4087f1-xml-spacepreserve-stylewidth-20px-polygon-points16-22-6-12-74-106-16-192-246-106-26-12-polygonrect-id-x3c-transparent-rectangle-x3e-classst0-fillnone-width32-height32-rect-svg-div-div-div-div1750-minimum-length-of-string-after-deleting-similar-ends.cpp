class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.length()-1;
        
        while(i<j)
        {
            if(s[i]==s[j])
            {
                char a=s[i];
                
                while(s[i]==a && i<=j)
                {
                    i++;
                }
                while(s[j]==a && i<=j)
                {
                    j--;
                }
            }
            else
            {
                break;
            }
        }
        return j-i+1;
    }
};