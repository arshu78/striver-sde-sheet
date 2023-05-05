class Solution {
public:
    int maxVowels(string s, int k) {
        int j=0,i=0;
        int maxi=INT_MIN;
        
        int cnt=0;
        
        while(j<s.size())
        {
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
            {
                cnt++;
            }
            while(j-i+1>k)
            {
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                {
                    cnt--;
                }
                i++;
            }
            
            maxi=max(maxi,cnt);
            j++;
        }
        
        return maxi;
    }
};