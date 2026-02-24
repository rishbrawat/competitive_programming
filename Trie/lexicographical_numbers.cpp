class Solution {
public:
    std::vector<int> lexicalOrder(int n) {
        std::vector<int> result;
        int current = 1;

        for (int i = 0; i < n; ++i) {
            result.push_back(current);
            
            if (current * 10 <= n) {
                // Dive deeper (1 -> 10 -> 100)
                current *= 10;
            } else {
                // Move laterally or climb back up
                while (current % 10 == 9 || current + 1 > n) {
                    current /= 10;
                }
                current += 1;
            }
        }
        
        return result;
    }
};