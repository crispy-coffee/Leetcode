class Solution {
public:
    int maxi = -1;
    vector<int>dp;
    void Recursion(int prev, int curr, vector<int>& nums, int target, int count){
        if(prev==nums.size()-1){
            maxi = max(maxi, count);
            return;
        }
        if(curr == nums.size())
            return;
        
        Recursion(prev, curr+1, nums, target, count);

        if(abs(nums[prev]-nums[curr])<=target){
            Recursion(curr, curr+1, nums, target, count+1);
        }
        
    }
    
    int Memoziation(int index,  vector<int>& nums, int target){
        if(index==nums.size()-1){
            return 0;
        }
        
        if(dp[index] != -1)
            return dp[index];
        
        int maxi = INT_MIN;
        for(int curr=index+1; curr<nums.size(); curr++){
            if(abs(nums[curr]-nums[index])<=target){
                maxi = max(maxi, Memoziation(curr, nums, target)+1);
            }
        }

        return dp[index] = maxi;
    }
    
    int Tabulation(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n+1, 0);

        for(int index=n-2; index>=0; index--){
            int maxi = INT_MIN;
            for(int curr=index+1; curr<nums.size(); curr++){
                if(abs(nums[curr]-nums[index])<=target){
                    maxi = max(maxi, dp[curr]+1);
                }
            }
            dp[index] = maxi;
        }

        return dp[0]<=0? -1:dp[0];
    }

    int maximumJumps(vector<int>& nums, int target) {
        
        // 1 Recursion
        // Recursion(0, 1, nums, target, 0);

        // 2 Memoization
        /*
        int n = nums.size();
        dp.resize(n+1, -1);
        int ans = Memoziation(0, nums, target);
        return ans<=0? -1: ans;
        */

        //3 Tabulation
        return Tabulation(nums, target);

    }
};
