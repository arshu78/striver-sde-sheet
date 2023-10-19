//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void f(int i,vector<int>& arr,vector<int> temp,set<vector<int>>& st)
    {
      
        st.insert(temp);
        for(int j=i;j<arr.size();j++)
        {
            if(i!=j && arr[j]==arr[j-1]) continue;
            
            temp.push_back(arr[j]);
            f(j+1,arr,temp,st);
            temp.pop_back();
        }
    }
    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        sort(arr.begin(),arr.end());
        set<vector<int>> st;
        vector<int> temp;
        f(0,arr,temp,st);
        vector<vector<int>> ans;
        for(auto it:st)
        {
            ans.push_back(it);
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
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends