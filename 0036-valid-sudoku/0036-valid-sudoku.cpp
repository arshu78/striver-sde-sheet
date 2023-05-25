class Solution {
public:
    bool check(int row,int col,vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            
            if(i!=row && board[row][col]!='.' && board[i][col]==board[row][col]) return false;
        }
        
        for(int i=0;i<9;i++)
        {
            if(i!=col && board[row][i]!='.' && board[row][i]==board[row][col]) return false;
        }
        for(int i=0;i<9;i++)
        {
            int r=3 * (row/3) + i/3;
            int c=3 * (col/3) + i%3;
            if(r!=row && c!=col && board[r][c]!='.' && board[r][c]==board[row][col]) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                      if(!check(i,j,board)) return false;
                }
              
            }
        }
        return true;
    }
};