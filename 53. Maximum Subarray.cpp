class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //1 Brute Force Approach
        /*
        int maxi = nums[0];
        for(int i=0; i<nums.size(); i++){
            int sum = 0;
            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
        */

        //2nd Kadane's Algorithm
        int ans = nums[0];
        int curr = 0;
        for(auto &i: nums){
            curr += i;
            ans = max(curr, ans);
            if(curr<0) curr = 0;
        }
        return ans;
    }
};