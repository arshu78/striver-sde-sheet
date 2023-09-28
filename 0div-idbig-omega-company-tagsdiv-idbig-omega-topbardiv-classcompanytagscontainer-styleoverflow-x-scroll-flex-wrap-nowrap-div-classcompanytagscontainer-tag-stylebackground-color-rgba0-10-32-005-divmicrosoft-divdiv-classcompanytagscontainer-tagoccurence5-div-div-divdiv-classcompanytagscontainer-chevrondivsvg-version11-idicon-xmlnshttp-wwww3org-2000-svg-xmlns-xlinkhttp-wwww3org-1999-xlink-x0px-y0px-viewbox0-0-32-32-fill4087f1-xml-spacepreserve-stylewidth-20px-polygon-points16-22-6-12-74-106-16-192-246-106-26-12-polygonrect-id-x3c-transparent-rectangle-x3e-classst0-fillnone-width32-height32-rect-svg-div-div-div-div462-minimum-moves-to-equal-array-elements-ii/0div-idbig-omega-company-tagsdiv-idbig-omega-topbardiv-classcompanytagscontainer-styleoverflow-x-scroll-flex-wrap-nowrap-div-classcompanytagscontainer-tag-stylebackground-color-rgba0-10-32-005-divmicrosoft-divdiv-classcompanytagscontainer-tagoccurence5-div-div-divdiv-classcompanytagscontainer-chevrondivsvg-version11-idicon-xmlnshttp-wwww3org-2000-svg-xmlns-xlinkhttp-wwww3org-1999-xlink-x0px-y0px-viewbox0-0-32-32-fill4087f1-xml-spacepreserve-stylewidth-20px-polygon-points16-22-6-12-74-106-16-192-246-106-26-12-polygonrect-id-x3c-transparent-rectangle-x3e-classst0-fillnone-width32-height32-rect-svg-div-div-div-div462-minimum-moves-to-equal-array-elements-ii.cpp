class Solution {
public:
    int minMoves2(vector<int>& nums) {
      vector<int> temp;
        int n=nums.size();
        for(auto it:nums) temp.push_back(it);
        sort(temp.begin(),temp.end());
      int ans=0;
            int m1,m2;
            m1=temp[n/2];
            
            
            for(auto it:nums)
            {
                if(it>m1) ans+=it-m1;
                else ans+=m1-it;
            }
        
        return ans;
        
    }
};