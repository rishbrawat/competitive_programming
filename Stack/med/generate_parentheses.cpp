class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }

    void backtrack(vector<string>& res, string& curr, int open, int close, int n) {
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            backtrack(res, curr, open + 1, close, n);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            backtrack(res, curr, open, close + 1, n);
            curr.pop_back();
        }
    }
};