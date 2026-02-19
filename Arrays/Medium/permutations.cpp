class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // Base case: If start reaches the end, we've formed a complete permutation
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            // 1. Swap the current element with the 'start' element
            swap(nums[start], nums[i]);

            // 2. Recursively generate permutations for the remaining elements
            backtrack(nums, start + 1, result);

            // 3. Backtrack: Swap back to restore the original state for the next loop
            swap(nums[start], nums[i]);
        }
    }
};