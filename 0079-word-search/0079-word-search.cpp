class Solution {
public:
    bool f(int i,int j,int n,int m,vector<vector<char>>& board,string word,int k)
    {
        if(k==word.size()) return true;
        if(i<0 || j<0 || i==n || j==m || board[i][j]!=word[k]) return false;
        board[i][j]='#';
        bool a=f(i+1,j,n,m,board,word,k+1);
        bool b=f(i-1,j,n,m,board,word,k+1);
        bool c=f(i,j+1,n,m,board,word,k+1);
        bool d=f(i,j-1,n,m,board,word,k+1);
        board[i][j]=word[k];
        return a || b || c || d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(f(i,j,n,m,board,word,0)) return true;
                }
            }
        }
        return false;
    }
};