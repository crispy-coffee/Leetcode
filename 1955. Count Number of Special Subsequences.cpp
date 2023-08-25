class Solution {
public:
    int recursion(int index, int prev, vector<int>& nums){
        if(index == nums.size() and prev == 3)
            return 1;
        
        if(index == nums.size())
            return 0;

        int answer = 0;

        if(nums[index] == prev){
            int include = recursion(index+1, prev+1, nums);
            int exclude = recursion(index+1, prev, nums);
            int repeat = recursion(index+1, prev, nums);
            answer = include+exclude+repeat;
        }else
            answer += recursion(index+1, prev, nums);

        return answer;
    }

    int mod = 1e9+7;
    vector<vector<int>> dp;
    int memoization(int index, int prev, vector<int>& nums){
        if(index == nums.size() and prev == 3)
            return 1;
        
        if(index == nums.size())
            return 0;
        
        if(dp[index][prev] != -1)
            return dp[index][prev];

        int answer = 0;

        if(nums[index] == prev){
            int include = memoization(index+1, prev+1, nums)%mod;
            int exclude = memoization(index+1, prev, nums)%mod;
            int repeat = memoization(index+1, prev, nums)%mod;
            answer = ((include+exclude)%mod +repeat)%mod;
        }else
            answer += memoization(index+1, prev, nums)%mod;

        return dp[index][prev] = answer;
    }

    int countSpecialSubsequences(vector<int>& nums) {

        // return recursion(0, 0, nums);

        dp.resize(nums.size(), vector<int>(4, -1));
        return memoization(0, 0, nums);

    }
};