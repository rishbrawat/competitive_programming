class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 1. Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // 2. Find the element just larger than the pivot
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // 3. Swap them
            std::swap(nums[i], nums[j]);
        }

            reverse(nums.begin() + i + 1, nums.end());
    }
};