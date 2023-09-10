class Solution {
public:

    // 1 Recursion
    int Recursion(vector<int>& nums, int target){

        if(target < 0)
            return 0;

        if(target == 0)
            return 1;

        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += Recursion(nums, target-nums[i]);
        }

        return ans;
    }

    // 2 Recursion With Memoization
    int RecursionWithMemoization(vector<int>& nums, int target, vector<int>& dp){
        if(target < 0)
            return 0;

        if(target == 0)
            return 1;

        if(dp[target] != -1)
            return dp[target];

        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += RecursionWithMemoization(nums, target-nums[i], dp);
        }

        return dp[target] = ans;
    }

    // 3 Tabulation
    int Tabulation(vector<int>& nums, int tar){
        vector<unsigned long long int > dp(tar+1, 0);
        dp[0] = 1;

        for(int target=1; target<=tar; target++){
            for(int i=0; i<nums.size(); i++){
                if(target-nums[i] >= 0){
                    cout << dp[target-nums[i]] << endl;
                    dp[target] += dp[target-nums[i]];
                }
            }
        }

        return (int)dp[tar];

    }

    int combinationSum4(vector<int>& nums, int target) {
        // 1 Recursion
        // return Recursion(nums, target);

        // 2 Recursion With Memoization
        vector<int> dp(target+1, -1);
        return RecursionWithMemoization(nums, target, dp);

        // 3 Tabulation
        // return Tabulation(nums, target);
    }
};