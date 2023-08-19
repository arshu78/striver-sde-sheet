//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public: 
     bool binarySearch(int key, int arr[], int n)
    {
        int low=0, high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==key)
                return true;
            else if(arr[mid]<key)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            set<int> ans;
            for(int i=0;i<n1;i++)
            {
                int target=A[i];
                
                int a1=binarySearch(target,B,n2);
                int a2=binarySearch(target,C,n3);
                
                if(a1 && a2) ans.insert(target);
            }
            
            vector<int> res(ans.begin(),ans.end());
            return res;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends