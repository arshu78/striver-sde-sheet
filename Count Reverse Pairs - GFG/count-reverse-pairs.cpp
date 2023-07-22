//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int merge(vector<int>& nums,int l,int mid,int h)
    {
        int j=mid+1;
        int cnt=0;
        for(int i=l;i<=mid;i++)
        {
            while(j<=h && nums[i] > 2* nums[j])
            {
                j++;
            }
            cnt+=(j-(mid+1));
        }
        
        vector<int> t;
        int i=l;
        j=mid+1;
        
        while(i<=mid && j<=h)
        {
            if(nums[i]<=nums[j])
            {
                t.push_back(nums[i++]);
            }
            else
            {
                t.push_back(nums[j++]);
            }
        }
        
        while(i<=mid) t.push_back(nums[i++]);
        
        while(j<=h) t.push_back(nums[j++]);
        
        for(int i=l;i<=h;i++)
        {
            nums[i]=t[i-l];
        }
        
        return cnt;
        
    }
    int mergesort(vector<int>& arr,int s,int e)
    {
        if(s>=e) return 0;
        
        int mid=(s+e)/2;
        int inv=mergesort(arr,s,mid);
        inv+=mergesort(arr,mid+1,e);
        inv+=merge(arr,s,mid,e);
        
        return inv;
    }
    int countRevPairs(int n, vector<int> arr) {
        return mergesort(arr,0,n-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends