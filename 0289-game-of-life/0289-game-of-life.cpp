class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        int r[]={-1,-1,0,1,1,1,0,-1};
        int c[]={0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<m;j++)
           {
               if(board[i][j]==1)
               {
                   int cnt=0;
                   
                   for(int k=0;k<8;k++)
                   {
                       int nrow= i + r[k];
                       int ncol= j + c[k];
                       
                       if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]==1)
                       {
                           cnt++;
                       }
                   }
                   
                   if(cnt<2 || cnt>3)
                   {
                       ans[i][j]=0;
                   }
                   else
                   {
                       ans[i][j]=1;
                   }
               }
               else
               {
                    int cnt=0;
                   
                   for(int k=0;k<8;k++)
                   {
                       int nrow= i + r[k];
                       int ncol= j + c[k];
                       
                       if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]==1)
                       {
                           cnt++;
                       }
                   }
                   
                   if(cnt==3) ans[i][j]=1;
               }
           }
        }
        
        board=ans;
    }
};