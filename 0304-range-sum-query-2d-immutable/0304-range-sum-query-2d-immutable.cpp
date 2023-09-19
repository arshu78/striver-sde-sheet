class NumMatrix {
public:
    vector<vector<int>> res;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        for(int j=0;j<m;j++)
        {
            for(int i=1;i<n;i++)
            {
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        res=matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int r=0,c=0,t=0;
        if(col1-1>=0)
        {
            r=res[row2][col1-1];
        }
        if(row1-1>=0)
        {
            c=res[row1-1][col2];
        }
        
        if(row1-1>=0 && col1-1>=0)
        {
            t=res[row1-1][col1-1];
        }
        
        return res[row2][col2]-r-c+t;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */