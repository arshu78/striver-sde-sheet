//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int a[]){
        vector<int> pass(31,-1);
        
        for(int i=0;i<2*N;i+=2)
        {
            pass[a[i]]=a[i+1];
        }
        
        queue<int> q;
        q.push(1);
        vector<int> vis(31,0);
        vis[1]=1;
        
        int cnt=0;
        while(!q.empty())
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                int u=q.front();
                q.pop();
                
                if(u==30) return cnt;
                for(int j=u+1;j<u+7;j++)
                {
                    if(j>30) break;
                    
                    if(vis[j]) continue;
                    else vis[j]=true;
                    
                    if(pass[j]==-1) q.push(j);
                    else q.push(pass[j]);
                    
                }
            }
            
            cnt++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends