//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    bool isPossible(int a[],int n,long long mid,int k)
    {
        int cnt=1,t=0;
        
        for(int i=0;i<n;i++)
        {
            if(a[i] > mid) return false;
            
            
            if(a[i] + t > mid) 
            {
                cnt++;
                t=a[i];
            }
            else
            {
                t+=a[i];
            }
        }
        
        return  cnt<=k;
        
    }
    long long minTime(int arr[], int n, int k)
    {
        int low=arr[0];
        long long high=0;
        
        for(int i=0;i<n;i++)
        {
            low=min(low,arr[i]);
            high+=arr[i];
        }
        
        while(low<=high)
        {
            long long mid=(low+high) >> 1;
            
            if(isPossible(arr,n,mid,k))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends