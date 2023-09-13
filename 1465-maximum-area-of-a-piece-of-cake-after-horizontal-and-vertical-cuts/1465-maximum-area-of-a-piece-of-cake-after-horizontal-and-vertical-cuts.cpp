
class Solution {
public:
    int mod=1e9 + 7;
    pair<long long int,long long int> f(vector<int>& a)
    {
        int diff=0;
        long long int first,last;
        for(int i=1;i<a.size();i++)
        {
            if(a[i] - a[i-1] > diff)
            {
                diff=a[i] - a[i-1];
                first=a[i-1];
                last=a[i];
            }
        }
        return {first,last};
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
            
        long maxHightOfPiece = max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.size() - 1]);
        long maxWidthOfPiece = max(verticalCuts[0], w - verticalCuts[verticalCuts.size() - 1]);
        
        for(int i=1;i<horizontalCuts.size();i++)
        {
            maxHightOfPiece=max(maxHightOfPiece,(long) horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
         for(int i=1;i<verticalCuts.size();i++)
        {
            maxWidthOfPiece=max(maxWidthOfPiece,(long) verticalCuts[i] - verticalCuts[i-1]);
        }
        return 1ll*(maxWidthOfPiece % mod * maxHightOfPiece % mod) % mod;
    }
};