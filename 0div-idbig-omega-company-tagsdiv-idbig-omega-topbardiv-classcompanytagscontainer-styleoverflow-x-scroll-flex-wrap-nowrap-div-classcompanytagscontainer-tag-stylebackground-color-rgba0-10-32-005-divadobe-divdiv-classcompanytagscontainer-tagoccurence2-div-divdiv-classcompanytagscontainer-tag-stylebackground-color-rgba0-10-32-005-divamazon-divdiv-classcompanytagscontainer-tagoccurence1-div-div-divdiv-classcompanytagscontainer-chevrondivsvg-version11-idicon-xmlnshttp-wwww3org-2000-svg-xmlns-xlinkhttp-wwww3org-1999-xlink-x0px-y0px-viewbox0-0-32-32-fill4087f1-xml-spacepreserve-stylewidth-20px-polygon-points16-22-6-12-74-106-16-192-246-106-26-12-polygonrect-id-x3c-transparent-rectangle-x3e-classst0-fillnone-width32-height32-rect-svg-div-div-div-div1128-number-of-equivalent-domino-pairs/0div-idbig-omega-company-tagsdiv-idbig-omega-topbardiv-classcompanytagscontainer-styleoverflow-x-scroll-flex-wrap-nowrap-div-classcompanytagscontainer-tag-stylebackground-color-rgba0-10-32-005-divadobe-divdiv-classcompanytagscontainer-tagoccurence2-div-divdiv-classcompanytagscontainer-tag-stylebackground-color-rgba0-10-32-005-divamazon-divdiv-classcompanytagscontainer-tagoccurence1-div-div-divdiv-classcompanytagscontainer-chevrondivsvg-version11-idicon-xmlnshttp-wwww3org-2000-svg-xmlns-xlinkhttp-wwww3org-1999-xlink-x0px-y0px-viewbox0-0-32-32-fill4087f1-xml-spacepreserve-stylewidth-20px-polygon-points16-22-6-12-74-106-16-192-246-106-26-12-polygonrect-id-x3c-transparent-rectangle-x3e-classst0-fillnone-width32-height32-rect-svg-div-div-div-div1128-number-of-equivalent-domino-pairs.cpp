class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
         map<pair<int,int>,int> seen;
        int result = 0;
        for(auto& v:d){
            if(v[0] > v[1]){
                swap(v[0], v[1]);
            }
            result += seen[make_pair(v[0],v[1])]++;
        }
        return result;
    }
};