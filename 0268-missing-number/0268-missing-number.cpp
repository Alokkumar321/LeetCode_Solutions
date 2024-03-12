class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans ^= nums[i] ^ (i + 1);
        }
        return ans;
    }
};