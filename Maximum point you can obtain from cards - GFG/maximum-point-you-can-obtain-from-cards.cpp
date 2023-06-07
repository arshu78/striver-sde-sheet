//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int k) {
         int sum=0;
        for(auto it:cardPoints)
        {
            sum+=it;
        }
        int maxi=INT_MAX;
        if(cardPoints.size()==k) return sum;
        int i=0,j=0;
        int sz=cardPoints.size()-k;
        int cur=0;
        while(j<cardPoints.size())
        {
          
                cur+=cardPoints[j];
         
            if(j-i+1==sz)
            {
                maxi=min(maxi,cur);
                cur-=cardPoints[i];
                i++;
               
            }
            j++;
        }
        
        return sum - maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends