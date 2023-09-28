class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even,odd;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        
        int l=0,j=0;
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        reverse(odd.begin(),odd.end());
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
                ans[i]=even[l++];
            }
            else
            {
                ans[i]=odd[j++];
            }
        }
        return ans;
    }
};