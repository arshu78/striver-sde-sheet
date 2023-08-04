//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char> st;
        
        for(auto it:s)
        {
            if(it=='(' || it=='+' || it=='-' || it=='*' || it=='/')
            {
                st.push(it);
            }
            else
            {
                bool isRed=true;
                if(it==')')
                {
       
                    while(!st.empty() && st.top()!='(')
                    {
                        char top=st.top();
                        if(top=='+' || top=='-' || top=='*' || top=='/') isRed=false;
                        
                        st.pop();
                    }
                    
                    if(isRed) return true;
                    
                    st.pop();
                }
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends