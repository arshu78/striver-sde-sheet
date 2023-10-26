//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class BrowserHistory {
public:
     // constructor to initialize object with homepage
     list<string> his;
     list<string> :: iterator it;
    BrowserHistory(string homepage) {
        his.push_back(homepage);
        it=his.begin();
    }
    
    // visit current url
    void visit(string url) {
        auto del=it;
        del++;
        his.erase(del,his.end());
        his.push_back(url);
        it++;
    }
    
    // 'steps' move backward in history and return current page
    string back(int steps) {
        while(it!=his.begin() && steps--)
        {
            it--;
        }
        return *it;
    }
    
    // 'steps' move forward and return current page
    string forward(int steps) {
          while(it!=--his.end() && steps--)
        {
            it++;
        }
        return *it;
    }
};

//{ Driver Code Starts.

int main()
{
    string homepage;
    cin >> homepage;
    
    BrowserHistory obj(homepage);
    
    int total_queries;
    cin >> total_queries;
    while(total_queries--)
    {
        int query;
        cin >> query;
        
        // if query = 1, visit()
        // if query = 2, back()
        // if query = 3, forward()
        
        if(query == 1) {
            string url;
            cin >> url;
            obj.visit(url);
        }
        else if(query == 2) {
            int steps;
            cin >> steps;
            cout << obj.back(steps) << endl;
        }
        else {
            int steps;
            cin >> steps;
            cout << obj.forward(steps) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends