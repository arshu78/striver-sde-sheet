class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> ans;
        for(int i=0;i<mat.size();i++)
        {
            int cnt=0;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1) cnt++;
            }
            ans.push({cnt,i});
            
            if(ans.size()>k) ans.pop();
        }
        
        //sort(ans.begin(),ans.end());
        vector<int> res(k);
        
        while(!ans.empty())
        {
            res[k-1]=ans.top().second;
            ans.pop();
            k--;
        }
        
        return res;
    }
};