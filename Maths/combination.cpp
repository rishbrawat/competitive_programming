class Solution {
public:
    void findCombinations(int index, int target, std::vector<int>& candidates, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base Case: We found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Base Case: Target exceeded or out of bounds
        if (index == candidates.size() || target < 0) {
            return;
        }

        // Choice 1: Pick the element (stay at the same index to allow reuse)
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            findCombinations(index, target - candidates[index], candidates, current, result);
            current.pop_back(); // Backtrack
        }

        // Choice 2: Skip the element (move to the next index)
        findCombinations(index + 1, target, candidates, current, result);
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        findCombinations(0, target, candidates, current, result);
        return result;
    }
};