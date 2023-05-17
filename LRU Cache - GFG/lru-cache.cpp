//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    map<int,int> m;
    int c;
    int size;
    list<int> l;
    map<int,list<int>::iterator> address;
    LRUCache(int cap)
    {
        c=cap;
        size=0;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
       if(m.find(key)==m.end()) 
       {
           return -1;
       }
       list<int>::iterator it=address[key];
       l.erase(it);
       address.erase(key);
       l.push_front(key);
       address[key]=l.begin();
       return m[key];
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(m.find(key)!=m.end())
        {
            list<int>::iterator it=address[key];
            l.erase(it);
            address.erase(key);
            m.erase(key);
            size--;
            
        }
        if(size==c) 
        {
            int k=l.back();
            l.pop_back();
            address.erase(k);
            m.erase(k);
            size--;
        }
        size++;
        l.push_front(key);
        address[key]=l.begin();
        m[key]=value;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends