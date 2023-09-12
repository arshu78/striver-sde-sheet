class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        
        int ans=INT_MIN;
        for(int i=0;i<points.size();i++)
        {
            int x1=points[i][0];
            int y1=points[i][1];
            
            while(!pq.empty() && (x1 - pq.top().second) > k) pq.pop();
            
            if(!pq.empty())
            {
                ans=max(ans,x1 + y1 + pq.top().first);
            }
            pq.push({(y1 - x1),x1});
        }
        
        return ans;
    }
};