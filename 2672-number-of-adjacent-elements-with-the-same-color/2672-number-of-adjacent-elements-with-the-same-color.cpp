class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),0),temp(n,0);
        int cnt=0;
        for(int i=0;i<queries.size();i++)
        {
            int ind=queries[i][0],col=queries[i][1];
            
            int prev= ind-1<0 ?0 : temp[ind-1];
            int next= ind+1>=n ?0 : temp[ind+1];
            int ocol=temp[ind];
            temp[ind]=col;
            if(prev!=0 && ocol==prev) cnt--;
            if(next!=0 && ocol==next) cnt--;
            
            if(col==prev) cnt++;
            if(col==next) cnt++;
            
            ans[i]=cnt;
        }
        return ans;
    }
};