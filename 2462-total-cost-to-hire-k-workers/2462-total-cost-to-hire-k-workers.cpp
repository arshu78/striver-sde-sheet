class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        long long int ans=0;
        int i=0,j=costs.size()-1,cnt=0;
        while(cnt<k)
        {
            while(pq1.size()<candidates && i<=j)
            {
                 pq1.push(costs[i++]);
            }
           
            while(pq2.size()<candidates && j>=i)
            pq2.push(costs[j--]);
            
            int cost1=pq1.size()>0?pq1.top():INT_MAX;
            int cost2=pq2.size()>0 ? pq2.top() : INT_MAX;
            
            if(cost1<=cost2)
            {
                ans+=cost1;
                pq1.pop();
            }
            else
            {
                ans+=cost2;
                pq2.pop();
            }
            cnt++;
        }
//         for(auto it:costs) pq.push(it);
        
//         while(k-- && !pq.empty())
//         {
//             ans+=pq.top();
//             pq.pop();
//         }
       return ans;
        
        
    }
};