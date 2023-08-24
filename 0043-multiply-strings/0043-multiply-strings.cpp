class Solution {
public:
    string multiply(string nums1, string nums2) {
       
        if(nums1=="0" || nums2=="0") return "0";
        
        
        string ans(size(nums1) + size(nums2),'0');
        for(int i=nums1.size()-1;i>=0;i--)
        {
            for(int j=nums2.size()-1;j>=0;j--)
            {
                int res=(ans[i+j+1] - '0') + (nums1[i] - '0') * (nums2[j] - '0');
                ans[i+j+1] = res%10 + '0';
                ans[i+j] += res / 10;
            }
        }
        
        if(ans[0]=='0') return ans.substr(1);
        
        return ans;
        
    }
};