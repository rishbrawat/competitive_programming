class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] > start)
                start = m[s[i]];
            m[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};