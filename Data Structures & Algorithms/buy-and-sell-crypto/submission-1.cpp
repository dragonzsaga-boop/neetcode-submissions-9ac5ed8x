class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxResult = 0;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            maxResult = max(maxResult, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxResult;
    }
};