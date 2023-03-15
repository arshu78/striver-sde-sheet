class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int cur=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            maxi=max(maxi,prices[i]-cur);
            cur=min(cur,prices[i]);
        }
        
        return maxi;
    }
};