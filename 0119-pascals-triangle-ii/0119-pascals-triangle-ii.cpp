class Solution {
public:
    vector<int> getRow(int numRows) {
         vector<vector<int>> ans(numRows+1);
        vector<int> res;
        
        for(int i=0;i<=numRows;i++)
        {
            
            ans[i].resize(i+1);
            ans[i][0]=ans[i][i]=1;
            for(int j=1;j<i;j++)
            {
                ans[i][j]=ans[i-1][j]  +ans[i-1][j-1];
            }
            res=ans[i];
        }
        return res;
    }
};