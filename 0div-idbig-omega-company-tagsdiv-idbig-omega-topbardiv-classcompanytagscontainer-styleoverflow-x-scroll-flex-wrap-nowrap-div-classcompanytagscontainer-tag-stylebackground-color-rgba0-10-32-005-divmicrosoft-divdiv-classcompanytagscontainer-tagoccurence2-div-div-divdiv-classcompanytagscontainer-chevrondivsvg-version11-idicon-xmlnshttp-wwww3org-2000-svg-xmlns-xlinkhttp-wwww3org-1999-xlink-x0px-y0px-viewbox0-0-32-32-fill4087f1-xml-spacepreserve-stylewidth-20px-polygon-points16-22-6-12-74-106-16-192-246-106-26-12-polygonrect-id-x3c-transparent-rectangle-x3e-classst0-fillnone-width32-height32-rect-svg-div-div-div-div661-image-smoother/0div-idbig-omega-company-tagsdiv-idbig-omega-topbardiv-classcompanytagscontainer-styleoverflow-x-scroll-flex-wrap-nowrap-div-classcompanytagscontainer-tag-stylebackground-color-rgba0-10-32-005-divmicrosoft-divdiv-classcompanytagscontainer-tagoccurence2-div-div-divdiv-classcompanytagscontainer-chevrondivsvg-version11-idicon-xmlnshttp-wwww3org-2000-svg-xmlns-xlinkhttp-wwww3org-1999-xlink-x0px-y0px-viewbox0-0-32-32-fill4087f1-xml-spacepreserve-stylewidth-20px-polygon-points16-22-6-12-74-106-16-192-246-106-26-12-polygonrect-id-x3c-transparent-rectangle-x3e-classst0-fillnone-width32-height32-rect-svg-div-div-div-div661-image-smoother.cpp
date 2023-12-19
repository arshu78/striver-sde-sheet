class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
       
       
        
        int n=img.size();
        int m=img[0].size();
         vector<vector<int>> ans(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum=0,cnt=0;
                for(int r=-1;r<=1;r++)
                {
                    for(int c=-1;c<=1;c++)
                    {
                        int nrow=i + r;
                        int ncol=j + c;
                        
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                        {
                            sum+=img[nrow][ncol];
                            cnt++;
                        }
                    }
                }
                ans[i][j]=floor((sum)/cnt);
            }
        }
        return ans;
    }
};