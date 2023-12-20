class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int p=0,cnt=0;
        for(auto it:prices)
        {
            if(it + p<=money)
            {
                p=p+it;
                cnt++;
                if(cnt==2) break;
            }
            else break;
        }
        
        if(cnt>=2) return abs(p-money);
        
        return money;
    }
};