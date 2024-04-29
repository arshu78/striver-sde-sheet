class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for (int num : nums) {
            x ^= num;
        }
        
        int ans = 0;
        k ^= x;
        while (k > 0) {
            ans += k & 1;
            k >>= 1;
        }
        
        return ans;
    }
};