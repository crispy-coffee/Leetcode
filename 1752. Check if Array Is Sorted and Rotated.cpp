class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i;
        for(i=1; i<n; i++){
            if(nums[i-1] > nums[i])
                break;
        }

        //if i==n means sorted
        if(i==n)
            return true;

        // i++ to check -1 from rotated index
        i++;
        for(i; i<n; i++){
            if(nums[i-1] > nums[i]){
                return false;
            }
        }

        if(nums[n-1] <= nums[0])
            return true;
        return false;

    }
};