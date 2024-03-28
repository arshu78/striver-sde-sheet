class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
          int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = 1;
        unordered_map<int, int> map;

        while (i < n) {
            map[nums[i]]++;
            while (map[nums[i]] > k) {
                map[nums[j]]--;
                j++;
            }
            ans = std::max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};