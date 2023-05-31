//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        stack<char> st;
       
        for(auto it:s)
        {
            int cnt=1;
                while(!st.empty() && st.top()==it)
                {
                    cnt++;
                    st.pop();
                }
                if(cnt<k)
                {
                    while(cnt>1)
                    {
                        st.push(it);
                        cnt--;
                    }
                    st.push(it);
                }
                
                
        }
        
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


};

//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}
// } Driver Code Ends