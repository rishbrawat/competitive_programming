class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int totalProfit = 0;
        
        // Start from the second day
        for (int i = 1; i < prices.size(); i++) {
            // If the price increased compared to yesterday, 
            // add the difference to our profit.
            if (prices[i] > prices[i - 1]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }
        
        return totalProfit;
    }
};