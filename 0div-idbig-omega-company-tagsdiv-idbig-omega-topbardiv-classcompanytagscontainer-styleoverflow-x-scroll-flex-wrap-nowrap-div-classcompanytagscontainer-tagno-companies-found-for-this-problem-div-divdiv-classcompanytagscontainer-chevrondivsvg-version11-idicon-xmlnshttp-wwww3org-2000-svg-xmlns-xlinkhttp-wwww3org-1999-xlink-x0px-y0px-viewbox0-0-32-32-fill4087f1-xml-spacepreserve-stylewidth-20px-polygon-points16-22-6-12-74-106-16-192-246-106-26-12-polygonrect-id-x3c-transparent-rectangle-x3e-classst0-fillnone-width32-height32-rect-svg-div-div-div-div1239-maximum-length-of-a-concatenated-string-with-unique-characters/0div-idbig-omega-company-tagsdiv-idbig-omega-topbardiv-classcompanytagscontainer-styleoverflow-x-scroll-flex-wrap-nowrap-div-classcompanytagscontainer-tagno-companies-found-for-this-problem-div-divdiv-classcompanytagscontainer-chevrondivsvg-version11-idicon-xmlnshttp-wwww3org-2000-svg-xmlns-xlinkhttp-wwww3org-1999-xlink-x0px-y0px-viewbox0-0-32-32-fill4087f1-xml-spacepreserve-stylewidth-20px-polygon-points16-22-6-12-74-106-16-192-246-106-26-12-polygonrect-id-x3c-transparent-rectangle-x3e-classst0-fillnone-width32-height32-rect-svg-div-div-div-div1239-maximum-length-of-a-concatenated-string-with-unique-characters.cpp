#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    static constexpr bitset<27> no= (1<<27)-1; // Set all 27 bits to 1. for edge case ["aa","bb"]
    int n;
    vector<string> arr;
    vector<bitset<27>> char_a;

    int f(int i, bitset<27> s){
        if (i == n) 
            return s.count(); //return the count of set bits in the bitset
    
        if (char_a[i]==no) return f(i+1, s);
        int has_ai=0;
        // Check if including the current string is possible
        if (!(s & char_a[i]).any()){
            has_ai=f(i+1, (s|char_a[i]));
        } 
        int no_ai = f(i+1, s);
        return max(has_ai, no_ai);
    }

    int maxLength(vector<string>& arr) {
        n=arr.size();
        this->arr=arr;
        char_a.resize(n);
        for (int i=0; i<n; i++)
            for(char c: arr[i]){
                if ( char_a[i][c-'a'+1]==1){
                    char_a[i]=no;
                    break;
                }
                char_a[i][c-'a'+1]=1;
            }   
        bitset<27> emptySet(0);
        return f(0, emptySet); 
    }
};