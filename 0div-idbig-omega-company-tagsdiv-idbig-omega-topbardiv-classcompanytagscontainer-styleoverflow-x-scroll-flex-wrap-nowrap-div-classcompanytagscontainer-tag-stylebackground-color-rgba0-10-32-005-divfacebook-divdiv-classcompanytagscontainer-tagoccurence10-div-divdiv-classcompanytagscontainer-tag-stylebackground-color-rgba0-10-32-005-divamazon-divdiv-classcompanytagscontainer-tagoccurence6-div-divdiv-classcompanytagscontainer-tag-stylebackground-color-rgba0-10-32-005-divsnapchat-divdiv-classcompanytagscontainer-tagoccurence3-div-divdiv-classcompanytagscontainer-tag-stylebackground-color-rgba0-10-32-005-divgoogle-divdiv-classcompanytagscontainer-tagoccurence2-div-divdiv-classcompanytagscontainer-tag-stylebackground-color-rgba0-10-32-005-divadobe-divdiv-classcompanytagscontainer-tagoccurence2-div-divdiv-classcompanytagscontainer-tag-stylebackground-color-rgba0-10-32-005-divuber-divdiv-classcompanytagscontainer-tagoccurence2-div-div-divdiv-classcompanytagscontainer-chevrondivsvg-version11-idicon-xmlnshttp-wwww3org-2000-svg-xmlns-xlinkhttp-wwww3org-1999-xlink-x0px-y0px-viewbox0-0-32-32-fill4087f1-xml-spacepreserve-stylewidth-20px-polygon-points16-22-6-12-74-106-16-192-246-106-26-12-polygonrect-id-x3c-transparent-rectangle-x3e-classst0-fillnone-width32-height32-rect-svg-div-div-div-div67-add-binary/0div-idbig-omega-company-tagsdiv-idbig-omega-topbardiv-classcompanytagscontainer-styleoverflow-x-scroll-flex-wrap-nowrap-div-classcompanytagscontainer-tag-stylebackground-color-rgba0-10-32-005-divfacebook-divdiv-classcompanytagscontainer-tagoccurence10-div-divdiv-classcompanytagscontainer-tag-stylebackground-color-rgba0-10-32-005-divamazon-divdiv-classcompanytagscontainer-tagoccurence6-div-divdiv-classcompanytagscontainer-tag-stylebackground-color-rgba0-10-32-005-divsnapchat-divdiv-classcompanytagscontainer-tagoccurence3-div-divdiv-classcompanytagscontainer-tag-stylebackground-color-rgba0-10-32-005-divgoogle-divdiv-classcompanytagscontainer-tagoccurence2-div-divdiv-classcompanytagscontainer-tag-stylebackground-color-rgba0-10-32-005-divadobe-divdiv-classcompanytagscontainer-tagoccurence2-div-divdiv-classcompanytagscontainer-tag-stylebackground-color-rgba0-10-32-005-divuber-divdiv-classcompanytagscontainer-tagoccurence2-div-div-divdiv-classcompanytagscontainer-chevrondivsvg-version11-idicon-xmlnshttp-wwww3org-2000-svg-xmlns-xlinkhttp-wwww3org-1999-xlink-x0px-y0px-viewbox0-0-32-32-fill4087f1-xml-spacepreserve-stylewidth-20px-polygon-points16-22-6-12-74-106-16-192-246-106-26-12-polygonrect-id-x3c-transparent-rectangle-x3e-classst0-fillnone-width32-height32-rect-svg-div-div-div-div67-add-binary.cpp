class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        string ans="";
        int carry=0,i=0,j=0;
        while(i<a.size() || j<b.size() || carry)
        {
            int sum=0;
            if(i<a.size())
            {
                sum+=a[i++] - '0';
            }
            if(j<b.size())
            {
                sum+=b[j++] - '0';
            }
            sum+=carry;
            
            if(sum==1)
            {
                ans+="1";
                carry=0;
            }
            else if(sum==2)
            {
                ans+="0";
                carry=1;
            }
            else if(sum==3)
            {
                ans+="1";
                carry=1;
            }
            else
            {
                ans+="0";
                carry=0;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};