class Solution {
public:
    int sbit(int i)
    {
        int cnt=0;
        while(i>0)
        {
            cnt+=i & 1;
            i>>=1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            ans.push_back(sbit(i));
        }
        return ans;
    }
};