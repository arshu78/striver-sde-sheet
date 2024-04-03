class Solution {
public:
    bool f(int i,int j,vector<vector<char>>& board,vector<vector<int>>& vis,string word,int c)
    {
        if(c==word.size()) return true;
        int n=board.size();
        int m=board[0].size();
        if(i<0 || j<0 || i==n || j==m || vis[i][j] || board[i][j]!=word[c]) return false;
        vis[i][j]=1;
        bool a=f(i+1,j,board,vis,word,c+1);
        bool b=f(i-1,j,board,vis,word,c+1);
        bool k=f(i,j+1,board,vis,word,c+1);
        bool d=f(i,j-1,board,vis,word,c+1);
       vis[i][j]=0;
        
        return a || b || k || d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vector<vector<int>> vis(n,vector<int>(m,0));
                if(f(i,j,board,vis,word,0)) return true;
            }
        }
        return false;
    }
};