//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1];
    }
    int minRemoval(int N, vector<vector<int>> &intervals) {
       sort(intervals.begin(),intervals.end(),cmp);
       
       vector<int> temp=intervals[0];
       int ans=0;
       for(int i=1;i<intervals.size();i++)
       {
           if(intervals[i][0]>=temp[1])
           {
               temp[1]=intervals[i][1];
           }
           else
           {
               ans++;
           }
       }
       
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends