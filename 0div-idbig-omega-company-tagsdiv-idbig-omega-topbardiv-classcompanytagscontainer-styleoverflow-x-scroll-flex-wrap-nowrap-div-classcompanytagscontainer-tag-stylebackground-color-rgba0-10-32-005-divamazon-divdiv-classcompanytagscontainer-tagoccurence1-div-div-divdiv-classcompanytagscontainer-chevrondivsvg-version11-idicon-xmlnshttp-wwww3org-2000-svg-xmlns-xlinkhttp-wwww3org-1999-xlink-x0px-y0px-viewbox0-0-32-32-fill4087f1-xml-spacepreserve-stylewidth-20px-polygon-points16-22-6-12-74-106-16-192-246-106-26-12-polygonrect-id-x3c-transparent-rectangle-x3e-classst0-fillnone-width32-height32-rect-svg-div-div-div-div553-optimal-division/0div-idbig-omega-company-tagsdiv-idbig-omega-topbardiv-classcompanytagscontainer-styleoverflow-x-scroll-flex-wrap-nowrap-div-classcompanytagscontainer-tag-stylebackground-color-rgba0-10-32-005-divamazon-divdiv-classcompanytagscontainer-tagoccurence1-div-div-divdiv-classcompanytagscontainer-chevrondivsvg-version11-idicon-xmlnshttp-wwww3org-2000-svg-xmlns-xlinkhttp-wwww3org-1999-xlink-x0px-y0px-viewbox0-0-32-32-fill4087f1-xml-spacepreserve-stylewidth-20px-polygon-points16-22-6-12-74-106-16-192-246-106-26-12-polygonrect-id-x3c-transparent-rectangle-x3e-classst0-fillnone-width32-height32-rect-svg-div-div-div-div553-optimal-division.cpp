class Solution {
public:
    int f(int i,vector<int> nums,int div,int& maxi)
    {
        if(i==0) return nums[i]/div;
        int q=0,p=0;
        if(div==-1)
        {
            q=f(i-1,nums,nums[i],maxi);
        }
        else
        {
            p=max(f(i-1,nums,nums[i]/div,maxi),f(i-1,nums,nums[i],maxi)/div);
        }
        return maxi=max(p,q);
    }
    string optimalDivision(vector<int>& nums) {
        if(nums.size()==1) return to_string(nums[0]);
        if(nums.size()==2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        
        string ans="";
        for(int i=0;i<nums.size()-1;i++)
        {
            ans+=to_string(nums[i]) + "/";
            if(i==0)
            ans+="(";
        }
        ans+=to_string(nums[nums.size()-1]) + ")";
        return ans;
    }
};