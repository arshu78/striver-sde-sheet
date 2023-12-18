class Solution {
public:
    bool check(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    long long countVowels(string word) {
        long long cur=0,prev=0,ans=0;
        
        for(int i=0;i<word.size();i++)
        {
            if(check(word[i])) 
            {
                cur=prev + i+ 1;
            }
            prev=cur;
            ans+=cur;
        }
        return ans;
    }
};