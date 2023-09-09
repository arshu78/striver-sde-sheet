//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        
        
        int total=r*c;
        vector<int> ans;
        int startrow=0,startcol=0;
        int endrow=r-1,endcol=c-1;
        
        int cnt=0;
        
        while(cnt<total)
        {
            for(int i=startcol;i<=endcol && cnt<total;i++)
            {
                ans.push_back(matrix[startrow][i]);
                cnt++;
            }
            startrow++;
            
            for(int i=startrow;i<=endrow && cnt<total;i++)
            {
                ans.push_back(matrix[i][endcol]);
                cnt++;
            }
            endcol--;
            
            for(int i=endcol;i>=startcol && cnt<total;i--)
            {
                ans.push_back(matrix[endrow][i]);
                cnt++;
            }
            endrow--;
            
             for(int i=endrow;i>=startrow && cnt<total;i--)
            {
                ans.push_back(matrix[i][startcol]);
                cnt++;
            }
            startcol++;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends