class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int l) {
        priority_queue<int> pq;
        int i;
        for(i=0;i<heights.size()-1;i++)
        {
            int diff=heights[i+1] - heights[i];
            if(diff<=0)
            {
                continue;
            }
            bricks-=diff;
            pq.push(diff);
            if(bricks<0)
            {
                bricks+=pq.top();
                pq.pop();
                l--;
            }
           if(l<0) break; 
        }
        return i;
    }
};