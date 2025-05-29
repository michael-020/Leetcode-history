class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int diff = 0;
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            mini = min(mini, prices[i]);
            diff = prices[i] - mini;

            maxProfit = max(maxProfit, diff);
        }   

        return maxProfit;
    }
};