//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long f(string &s,char a,char b)
    {
        long long cnt=0;
        stack<char> st;
        for(auto it:s)
        {
            if(!st.empty() && st.top()==a && it==b) 
            {
                cnt++;
                st.pop();
            }
            else
            {
                st.push(it);
            }
        }
        
        s="";
        while(!st.empty())
        {
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        
        return cnt;
    }
    long long solve(int X,int Y,string S){
      long long ca=0,cb=0;
      if(X>Y)
      {
          ca= f(S,'p','r');
          cb= f(S,'r','p');
      }
      else
      {
          cb= f(S,'r','p');
          ca =f(S,'p', 'r');
      }
      
      return (long long) ca*X + cb*Y;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends