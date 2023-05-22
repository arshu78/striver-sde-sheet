class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),r=0,c=0;
        vector<int> ans(n*m,0);
        if(mat.size()==0) return ans;
        for(int i=0;i<ans.size();i++)
        {
            ans[i]=mat[r][c];
            if((r+c)%2==0)
            {
                if(c==n-1)
                {
                    r++;
                }
                else if(r==0)
                {
                    c++;
                }
                else
                {
                    r--;
                    c++;
                }
            }
            else
            {
                if(r==m-1)
                {
                    c++;
                }
                else if(c==0)
                {
                    r++;
                }
                else
                {
                    r++;
                    c--;
                }
            }
        }
        
        return ans;
    }
};