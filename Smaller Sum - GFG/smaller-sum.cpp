//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:

    
    vector<long long> smallerSum(int n,vector<int> &arr){
        
       vector<int> arrcpy=arr; 
       sort(arr.begin(),arr.end());
        
        vector<long long> ans;
        vector<long long> pre{0};
        
       for(int i=0; i<n; i++)
            pre.push_back(pre[i]+arr[i]);
        for(int i=0;i<n;i++)
        {
            int ind=lower_bound(arr.begin(),arr.end(),arrcpy[i]) - arr.begin();
            
            ans.push_back(pre[ind]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends