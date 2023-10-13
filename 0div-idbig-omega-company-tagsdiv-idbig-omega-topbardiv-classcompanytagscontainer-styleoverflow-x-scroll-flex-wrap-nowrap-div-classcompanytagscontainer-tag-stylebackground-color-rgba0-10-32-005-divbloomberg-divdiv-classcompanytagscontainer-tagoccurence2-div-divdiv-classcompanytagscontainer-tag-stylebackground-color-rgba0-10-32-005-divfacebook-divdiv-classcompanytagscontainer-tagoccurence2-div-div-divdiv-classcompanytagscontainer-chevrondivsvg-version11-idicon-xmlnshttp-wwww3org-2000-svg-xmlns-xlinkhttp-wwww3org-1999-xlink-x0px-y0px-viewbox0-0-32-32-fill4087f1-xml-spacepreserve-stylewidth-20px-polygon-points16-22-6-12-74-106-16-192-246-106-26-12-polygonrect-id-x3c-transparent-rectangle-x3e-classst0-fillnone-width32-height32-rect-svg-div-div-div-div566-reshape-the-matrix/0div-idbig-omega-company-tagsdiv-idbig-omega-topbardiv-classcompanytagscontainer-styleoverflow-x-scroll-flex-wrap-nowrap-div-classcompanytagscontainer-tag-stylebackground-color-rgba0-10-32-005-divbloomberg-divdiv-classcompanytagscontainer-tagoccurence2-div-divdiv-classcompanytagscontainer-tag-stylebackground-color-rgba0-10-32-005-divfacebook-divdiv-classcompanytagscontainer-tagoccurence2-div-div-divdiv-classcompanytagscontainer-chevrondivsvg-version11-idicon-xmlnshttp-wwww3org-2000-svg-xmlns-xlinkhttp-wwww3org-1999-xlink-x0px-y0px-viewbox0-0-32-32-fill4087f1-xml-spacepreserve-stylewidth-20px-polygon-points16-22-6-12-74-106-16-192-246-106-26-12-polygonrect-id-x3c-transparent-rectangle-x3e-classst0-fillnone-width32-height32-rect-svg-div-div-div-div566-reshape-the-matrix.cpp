class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        if(mat.size() * mat[0].size()!=r*c) return mat;
        vector<int> arr;
        for(auto it:mat)
        {
            for(auto i:it) arr.push_back(i);
        }
        
        int k=0;
        vector<vector<int>> ans(r,vector<int>(c,0));
        
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                ans[i][j]=arr[k++];
            }
        }
        return ans;
        
    }
};