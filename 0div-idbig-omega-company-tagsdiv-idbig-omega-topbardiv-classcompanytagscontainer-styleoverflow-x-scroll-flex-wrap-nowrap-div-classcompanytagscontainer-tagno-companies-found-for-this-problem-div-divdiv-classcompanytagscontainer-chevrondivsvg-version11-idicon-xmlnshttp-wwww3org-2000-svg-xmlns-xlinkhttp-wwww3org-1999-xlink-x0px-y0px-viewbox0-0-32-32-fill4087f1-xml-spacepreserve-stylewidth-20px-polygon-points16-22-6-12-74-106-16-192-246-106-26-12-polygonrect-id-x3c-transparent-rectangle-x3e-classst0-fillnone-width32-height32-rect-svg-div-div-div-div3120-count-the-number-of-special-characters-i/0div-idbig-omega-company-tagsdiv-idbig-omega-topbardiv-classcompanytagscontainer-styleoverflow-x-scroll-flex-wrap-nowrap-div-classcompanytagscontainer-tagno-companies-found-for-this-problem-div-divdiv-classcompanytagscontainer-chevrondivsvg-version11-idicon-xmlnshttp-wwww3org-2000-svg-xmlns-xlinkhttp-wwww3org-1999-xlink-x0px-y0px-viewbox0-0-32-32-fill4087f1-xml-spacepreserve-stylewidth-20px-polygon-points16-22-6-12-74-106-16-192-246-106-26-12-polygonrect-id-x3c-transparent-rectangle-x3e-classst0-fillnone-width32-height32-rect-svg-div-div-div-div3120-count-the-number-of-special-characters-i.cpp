class Solution {
public:
    int numberOfSpecialChars(string word) {
       unordered_map<char, int> map;

        int cnt(0);
        bool upperFlag;
        char currKey;
        for (char& ch : word) {
            upperFlag = isupper(ch);
            currKey = upperFlag ? char(ch + 32) : ch; 
            auto it = map.find(currKey);
            if (it == map.end()) { 
                if (upperFlag) map[currKey] = 1;
                else map[currKey] = 2;
            } 
            else {
                switch (map[currKey]) {
                case 1:               
                    if (!upperFlag) { 
                        map[currKey] = 3;
                        cnt++;
                    }
                    break;
                case 2:              
                    if (upperFlag) { 
                        map[currKey] = 3;
                        cnt++;
                    }
                    break;
                case 3: 
                    break;
                }
            }
        }
        return cnt;
    }
};