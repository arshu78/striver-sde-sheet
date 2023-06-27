//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
    bool isWordExist(vector<vector<char>>& board, string word) {
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends