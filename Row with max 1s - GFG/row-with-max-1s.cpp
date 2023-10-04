//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	   
	   int ans=0,r=-1;
	   for(int i=0;i<n;i++)
	   {
	       vector<int> temp=arr[i];
	       int l=0,h=m-1;
	       int a=0;
	       while(l<=h)
	       {
	           int mid=(l+h)>>1;
	           if(temp[mid] >=1)
	           {
	               h=mid-1;
	           }
	           else
	           {
	               l=mid+1;
	           }
	       }
	       int cnt=(m - l);
	       
	       if(cnt>ans)
	       {
	           ans=cnt;
	           r=i;
	       }
	   }
	   return r;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends