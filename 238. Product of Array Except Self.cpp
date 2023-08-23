class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
            return nums;

        vector<int> left(n), right(n), v(n);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i=1; i<n-1; i++){
            left[i] = left[i-1] * nums[i];
            right[n-i-1] = right[n-i] * nums[n-i-1];
        }

        left[n-1] = left[n-2] * nums[n-1];
        right[0] = right[1] * nums[0];


        // for(int i=0; i<n; i++){
        //     int lefty = 1, righty = 1;
        //     if(i>0)
        //         lefty = left[i-1];
        //     if(i<n-1)
        //         righty = right[i+1];
        //     v.push_back(lefty*righty);
        // }
        
        v[0] = right[1];
        v[n-1] = left[n-2];

        for(int i=1; i<n-1; i++){
            v[i] = left[i-1] * right[i+1];
        }

        return v;
    }
};