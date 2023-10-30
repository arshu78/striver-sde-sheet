class Solution {
public:
    int f(int a)
    {
        int cnt=0;
        while(a>0)
        {
            if(a&1) cnt++;
            a=a>>1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++)
        {
            int b=f(arr[i]);
            v.push_back({b,arr[i]});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(auto it:v) ans.push_back(it.second);
        
        return ans;
    }
};