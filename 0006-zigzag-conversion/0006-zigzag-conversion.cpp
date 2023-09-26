class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> temp(numRows);
        
        if(numRows==1) return s;
        int i=0;
        bool flag=false;
        for(auto it:s)
        {
            temp[i]+=it;
            
            if(i==0 || i==numRows-1)
            {
                flag=!flag;
            }
            
            if(flag)
            {
                i++;
            }
            else i--;
        }
        
        string ans="";
        for(auto it:temp)
        {
            ans+=it;
        }
        return ans;
    }
};