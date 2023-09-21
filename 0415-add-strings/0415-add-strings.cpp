class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry=0;
        string ans="";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int i=0,j=0;
        int n=num1.size(),m=num2.size();
        while(i<n || j<m || carry)
        {
            int sum=0;
            if(i!=n)
            {
                sum+=num1[i] - '0';
                i++;
            }
            if(j!=m)
            {
                sum+=num2[j] - '0';
                j++;
            }
            sum+=carry;
            carry=sum / 10;
            sum=sum % 10;
            ans+=to_string(sum);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};