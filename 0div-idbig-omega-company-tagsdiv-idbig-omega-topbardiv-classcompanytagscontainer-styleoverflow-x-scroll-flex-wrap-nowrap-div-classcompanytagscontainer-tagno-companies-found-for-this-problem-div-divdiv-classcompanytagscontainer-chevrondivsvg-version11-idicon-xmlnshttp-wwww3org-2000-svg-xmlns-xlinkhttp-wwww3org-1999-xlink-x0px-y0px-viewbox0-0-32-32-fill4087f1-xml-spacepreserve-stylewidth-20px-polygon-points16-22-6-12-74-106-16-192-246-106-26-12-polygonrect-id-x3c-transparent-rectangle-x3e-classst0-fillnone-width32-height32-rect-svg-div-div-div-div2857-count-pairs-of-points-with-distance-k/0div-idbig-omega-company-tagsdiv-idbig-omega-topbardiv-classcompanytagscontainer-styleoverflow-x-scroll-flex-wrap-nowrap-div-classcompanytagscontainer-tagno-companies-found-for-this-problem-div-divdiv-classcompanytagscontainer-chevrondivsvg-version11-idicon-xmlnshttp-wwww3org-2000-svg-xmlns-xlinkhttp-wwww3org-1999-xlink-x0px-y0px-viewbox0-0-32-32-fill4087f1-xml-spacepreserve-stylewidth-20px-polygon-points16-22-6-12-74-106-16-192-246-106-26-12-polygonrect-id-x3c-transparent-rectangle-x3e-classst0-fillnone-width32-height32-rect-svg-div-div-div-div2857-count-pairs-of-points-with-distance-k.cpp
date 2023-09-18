class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int ans=0;
        map<pair<int,int>,int> mp;
        
        for(auto it:coordinates)
        {
             int x1=it[0],y1=it[1];
            
            for(int i=0;i<=k;i++)
            {
                int x2=x1 ^ i;
                int y2=y1 ^ (k-i);
                
                ans+=mp[{x2,y2}];
                
            }
            
            mp[{x1,y1}]++;
        }
        
        return ans;
    }
};