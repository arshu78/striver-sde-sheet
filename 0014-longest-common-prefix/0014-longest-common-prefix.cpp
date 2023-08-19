class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       
        string ans="";
        for(int i=0;i<strs[0].size();i++)
        {
            char ch=strs[0][i];
            
            int j=1;
            bool flag=true;
            while(j<strs.size())
            {
                if(strs[j].size()<i || strs[j][i]!=ch)
                {
                    flag=false;
                    break;
                }
                j++;
            }
            
            if(flag)
            {
                ans.push_back(ch);
            }
            else
                break;
        }
        
        return ans;
    }
};