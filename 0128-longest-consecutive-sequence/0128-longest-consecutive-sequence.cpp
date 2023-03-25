class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int> st;
        
        for(auto it:nums) st.insert(it);
        
        for(auto it:nums)
        {
            if(st.find(it-1)==st.end())
            {
                int cnt=1,num=it+1;
                while(st.find(num)!=st.end())
                {
                    cnt++;
                    num+=1;
                }
                
                ans=max(ans,cnt);
                
            }
        }
        
        return ans;
    }
};