class Solution {
public:
    // 1 Recursion
    int Recursion(vector<int>&nums ,int index, int prev, bool positive){
        if(index == nums.size())
            return 0;
        
        int include=0, exclude=0;
        // Pehle wala positive tha aur abhi wala negative hai 
        if(positive and (nums[index]-nums[prev] < 0)){
            include = 1 + Recursion(nums, index+1, index, !positive);

        // pehel wala negative tha aur abhi wala positive hai;
        }else if(!positive and (nums[index]-nums[prev]>0)){
            include = 1 + Recursion(nums, index+1, index, !positive);
        }
        
        // koi bhi case ho exclude common hi tha
        exclude = Recursion(nums, index+1, prev, positive);

        return max(include, exclude);
    }

    int Recursion(vector<int>&nums ,int index, int prev, bool positive, vector<vector<vector<int>>>& dp){
        if(index == nums.size())
            return 0;
        
        if(dp[index][prev][positive] != -1)
            return dp[index][prev][positive];

        int include=0, exclude=0;
        // Pehle wala positive tha aur abhi wala negative hai 
        if(positive and (nums[index]-nums[prev] < 0)){
            include = 1 + Recursion(nums, index+1, index, !positive, dp);

        // pehel wala negative tha aur abhi wala positive hai;
        }else if(!positive and (nums[index]-nums[prev]>0)){
            include = 1 + Recursion(nums, index+1, index, !positive, dp);
        }
        
        // koi bhi case ho exclude common hi tha
        exclude = Recursion(nums, index+1, prev, positive, dp);

        return dp[index][prev][positive] = max(include, exclude);
    }

    int wiggleMaxLength(vector<int>& nums) {
        // 1 Recursion
        int n = nums.size();
        // return 1+max(Recursion(nums, 1, 0, true), Recursion(nums, 1, 0, false));


        // 2 Memoization
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return 1+max(Recursion(nums, 1, 0, true, dp), Recursion(nums, 1, 0, false, dp));
    }
};

