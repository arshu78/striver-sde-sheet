class Solution {
public:

    ///is the element indegree is 0 store it in ans
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> seen(n,0);
        vector<int> res;

        for(auto it:edges)
        {
            seen[it[1]]=1;
        }

        for(int i=0;i<n;i++)
        {
            if(seen[i]==0) res.push_back(i);
        }
        return res;
    }
};