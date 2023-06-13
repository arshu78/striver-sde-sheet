class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int m=grid[0].size();
        int n=grid.size();
        vector<vector<int>> cols;
        for(int j=0;j<m;j++)
        {
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                temp.push_back(grid[i][j]);
            }
            cols.push_back(temp);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            vector<int> temp=grid[i];
            
            for(int j=0;j<n;j++)
            {
                if(temp==cols[j]) cnt++;
            }
        }
        return cnt;
    }
};