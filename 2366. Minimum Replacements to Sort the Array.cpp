class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        double prev = nums.back();

        long long kharcha = 0;

        for(int i=n-2; i>=0; i--){
            if(nums[i] <= prev){
                prev = nums[i];
                continue;
            }
            
            long long newkharcha = ceil(nums[i]/prev);
            prev = nums[i]/newkharcha;

            kharcha += (newkharcha-1);
        }

        return kharcha;
    }
};