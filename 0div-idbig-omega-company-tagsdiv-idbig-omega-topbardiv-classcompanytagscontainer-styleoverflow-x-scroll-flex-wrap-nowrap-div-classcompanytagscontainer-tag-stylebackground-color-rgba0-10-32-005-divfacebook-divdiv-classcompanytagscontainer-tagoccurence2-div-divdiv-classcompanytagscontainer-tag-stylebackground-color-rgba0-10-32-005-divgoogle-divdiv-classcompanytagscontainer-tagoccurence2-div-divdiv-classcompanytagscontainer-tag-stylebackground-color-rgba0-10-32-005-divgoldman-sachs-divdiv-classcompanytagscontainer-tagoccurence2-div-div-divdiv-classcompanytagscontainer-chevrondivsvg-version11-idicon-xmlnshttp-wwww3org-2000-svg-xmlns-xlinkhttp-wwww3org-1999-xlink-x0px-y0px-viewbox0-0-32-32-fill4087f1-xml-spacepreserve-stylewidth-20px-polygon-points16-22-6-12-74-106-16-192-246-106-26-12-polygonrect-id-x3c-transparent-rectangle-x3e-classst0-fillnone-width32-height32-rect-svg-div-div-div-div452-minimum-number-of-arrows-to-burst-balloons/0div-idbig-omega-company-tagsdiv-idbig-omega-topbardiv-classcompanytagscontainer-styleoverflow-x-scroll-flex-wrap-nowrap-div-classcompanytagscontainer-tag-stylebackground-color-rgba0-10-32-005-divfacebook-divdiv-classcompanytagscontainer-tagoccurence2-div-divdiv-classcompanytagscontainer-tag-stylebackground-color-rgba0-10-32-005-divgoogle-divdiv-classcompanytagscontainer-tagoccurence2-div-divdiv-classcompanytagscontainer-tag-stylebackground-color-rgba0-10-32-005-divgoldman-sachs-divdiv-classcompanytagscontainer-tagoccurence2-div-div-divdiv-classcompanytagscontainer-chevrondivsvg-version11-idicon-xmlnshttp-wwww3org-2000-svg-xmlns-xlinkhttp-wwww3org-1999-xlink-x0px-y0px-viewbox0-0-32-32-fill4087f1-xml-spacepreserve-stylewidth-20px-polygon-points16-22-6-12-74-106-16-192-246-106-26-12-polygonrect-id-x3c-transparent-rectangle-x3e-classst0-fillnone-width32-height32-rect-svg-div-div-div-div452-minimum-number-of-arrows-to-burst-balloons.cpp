class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=1;
        sort(points.begin(),points.end());
        int last=points[0][1];
        for(auto it:points)
        {
            if(it[0]>last)
            {
                ans++;
                last=it[1];
            }
            last=min(last,it[1]);
        }
        return ans;
    }
};