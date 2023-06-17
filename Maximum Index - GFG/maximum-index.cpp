//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
         int lmin[n],rmax[n];
        
        lmin[0]=arr[0];
        rmax[n-1]=arr[n-1];
        
        //calculating minimum from left side
        
        for(int i=1;i<n;i++)
        {
            lmin[i]=min(lmin[i-1],arr[i]);
        }
        
        //calculating for right side
        
        for(int i=n-2;i>=0;i--)
        {
            rmax[i]=max(rmax[i+1],arr[i]);
        }
        
        //storing the answer
        
        int i=0,j=0,ans=-1;
        
        while(i<n && j<n)
        {
            if(lmin[i]<=rmax[j]) // check for less than rmax[j] 
            {
                ans=max(ans,j-i); 
                j++; // here we know the greater element is always on right ot rmax
            }
            else
            {
                i++; // beacause the minimum element always on right of lmax;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends