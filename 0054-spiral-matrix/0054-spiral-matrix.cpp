class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        
        vector<int> ans;
        int row=a.size();
        int col=a[0].size();
        
        int total=row*col;
        int count=0;
        
        int startRow=0;
        int startCol=0;
        int endRow=row-1;
        int endCol=col-1;
        
        while(count<total)
        {
            //Traverse Start Row
            
            for(int i=startCol;count<total && i<=endCol;i++)
            {
                ans.push_back(a[startRow][i]);
                count++;
            }
            startRow++;
            
            //Traverse End Column
            for(int i=startRow;count<total && i<=endRow;i++)
            {
                ans.push_back(a[i][endCol]);
                count++;
            }
            endCol--;
            
            //Traverse End row
            for(int i=endCol;count<total && i>=startCol;i--)
            {
                ans.push_back(a[endRow][i]);
                count++;
            }
            endRow--;
            //Traverse start coloumn
            for(int i=endRow;count<total && i>=startRow;i--)
            {
                ans.push_back(a[i][startCol]);
                count++;
            }
            startCol++;
            
        }
        return ans;
    }
};