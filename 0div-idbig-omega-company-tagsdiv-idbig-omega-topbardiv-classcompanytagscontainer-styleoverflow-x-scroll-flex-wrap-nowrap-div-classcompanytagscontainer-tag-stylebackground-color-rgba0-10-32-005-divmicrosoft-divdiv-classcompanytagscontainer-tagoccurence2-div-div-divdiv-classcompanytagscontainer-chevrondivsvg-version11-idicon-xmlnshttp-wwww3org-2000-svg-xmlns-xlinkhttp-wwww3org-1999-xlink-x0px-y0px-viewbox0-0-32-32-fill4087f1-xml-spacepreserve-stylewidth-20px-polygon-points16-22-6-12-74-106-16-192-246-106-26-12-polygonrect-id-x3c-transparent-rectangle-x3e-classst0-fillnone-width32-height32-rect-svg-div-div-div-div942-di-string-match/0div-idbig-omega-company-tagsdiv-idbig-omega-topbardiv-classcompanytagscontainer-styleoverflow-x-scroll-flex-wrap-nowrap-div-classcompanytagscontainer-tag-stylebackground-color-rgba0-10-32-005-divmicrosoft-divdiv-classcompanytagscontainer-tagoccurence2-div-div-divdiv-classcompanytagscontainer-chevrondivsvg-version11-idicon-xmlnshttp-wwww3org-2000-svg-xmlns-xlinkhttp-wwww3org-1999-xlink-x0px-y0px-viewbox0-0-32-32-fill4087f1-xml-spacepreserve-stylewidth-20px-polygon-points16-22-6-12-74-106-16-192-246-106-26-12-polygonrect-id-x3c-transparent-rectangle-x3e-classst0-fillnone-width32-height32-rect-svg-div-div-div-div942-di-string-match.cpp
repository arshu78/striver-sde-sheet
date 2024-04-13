class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.length();
        vector<int> ans;
        int head=0;
        for(int i=0;i<s.length();i++ ){
            if(s[i]=='I'){
                ans.push_back(head);
               head++;
            }
            else{
                 ans.push_back(n);
                 n--;
            }
        }
           ans.push_back(head);
        return ans;
    }
};