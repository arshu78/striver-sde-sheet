class Solution {
public:
    int v(string &str,int s,int e)
    {
        int cnt=0;
        for(int i=s;i<=e;i++)
        {
       //     cout<<str[i]<<" ";
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') cnt++;
        }
      //  cout<<endl;
        return cnt;
    }
    bool halvesAreAlike(string s) {
        
        int n=s.length();
        int m=n/2;
        
        return v(s,0,m-1)==v(s,m,n);
    }
};