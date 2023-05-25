//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(int row,int col,vector<vector<int>>& board)
    {
        for(int i=0;i<9;i++)
        {
            
            if(i!=row && board[row][col]!=0 && board[i][col]==board[row][col]) return false;
        }
        
        for(int i=0;i<9;i++)
        {
            if(i!=col && board[row][i]!=0 && board[row][i]==board[row][col]) return false;
        }
        for(int i=0;i<9;i++)
        {
            int r=3 * (row/3) + i/3;
            int c=3 * (col/3) + i%3;
            if(r!=row && c!=col && board[r][c]!=0 && board[r][c]==board[row][col]) return false;
        }
        return true;
    }
    int isValid(vector<vector<int>> board){
         int n=board.size();
        int m=board[0].size();
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!=0)
                {
                      if(!check(i,j,board)) return false;
                }
              
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends