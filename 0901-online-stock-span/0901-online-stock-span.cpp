class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i;
    StockSpanner() {
       i=0;
    }
    
    int next(int price) {
        int res=0;
        while(!st.empty() && st.top().first<=price)
            {
                st.pop();
            }
            if(!st.empty()) 
            res=i-st.top().second;
            else
            res=i+1;
            
            st.push({price,i});
            i++;
            return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */