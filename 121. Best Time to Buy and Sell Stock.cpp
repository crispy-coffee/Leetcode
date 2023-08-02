class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        int n = prices.size();
        vector<int> minimum(n,0);
        minimum[n-1] = prices[n-1];

        for(int i=n-2; i>=0; i--){
            minimum[i] = max(minimum[i+1],prices[i]);
        }

        int ans, maxi = 0;

        for(int i=0; i<n; i++){
            ans = minimum[i]-prices[i];
            maxi = max(ans,maxi);
        }
        return maxi;
        */

        int profit = 0;
        int mini = prices[0];
        int n = prices.size();
        for(int i=1; i<n ;i++){
            int diff = prices[i] - mini;
            profit = max(profit, diff);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};












