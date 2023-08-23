class Solution {
public:
    // 1 Recursion
    int Recursion(vector<int>& coins, int amount){
        if(amount < 0){
            return INT_MAX;
        }

        if(amount == 0){
            return 0;
        }

        int mini = INT_MAX;
        for(int i=0 ;i<coins.size(); i++){
            int ans = Recursion(coins, amount-coins[i]);

            if(ans != INT_MAX){
                mini = min(mini, ans+1);
            }
        }

        return mini;
    }

    // 2 Recursion With Memoization
    int Memoization(vector<int>& coins, int amount, vector<int>& dp){
        if(amount < 0){
            return INT_MAX;
        }

        if(amount == 0){
            return 0;
        }

        if(dp[amount] != -1)
            return dp[amount];

        int mini = INT_MAX;
        for(int i=0 ;i<coins.size(); i++){
            int ans = Memoization(coins, amount-coins[i], dp);

            if(ans != INT_MAX){
                mini = min(mini, ans+1);
            }
        }

        return dp[amount] = mini;
    }

    // 3 Tabulation
    int Tabulation(vector<int>& coins, int amount){
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int amt = 1; amt<=amount; amt++){
            int mini = INT_MAX;

            for(int i=0 ;i<coins.size(); i++){
                int ans = INT_MAX;

                if(amt-coins[i] >= 0)
                ans = dp[amt-coins[i]];

                if(ans != INT_MAX){
                    mini = min(mini, ans+1);
                }
            }
            dp[amt] = mini;
        }

        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        // int n = coins.size();

        // 1 Recursion
        // int ans =  Recursion(coins, amount);

        // 2 Recursion With Memoization
        // vector<int> dp(amount+1, -1);
        // int ans = Memoization(coins, amount, dp);

        // 3 Tabulation
        int ans = Tabulation(coins, amount);

        return ans != INT_MAX? ans:-1;
        
    }
};