class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& mat)
    {
        bool a=true,b=true;
        for(int col=0;col<mat[0].size();col++)
        {
            if(col!=j && mat[i][col]==1)
            {
                a=false;
                break;
            }
        }
         for(int row=0;row<mat.size();row++)
        {
            if(row!=i && mat[row][j]==1)
            {
                b=false;
                break;
            }
        }
        return a && b;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                {
                    if(check(i,j,mat)) ans++;
                }
            }
        }
        return ans;
    }
};