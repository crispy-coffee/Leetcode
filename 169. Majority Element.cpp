class Solution {
public:
    /*int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        int count=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]==nums[i]){
                count++;
            }else{
                maxi = max(maxi,count);
                count=1;
            }
        }
        maxi = max(maxi,count);
        return maxi;
    }*/

    /*int majorityElement(vector<int>& nums){
        sort(begin(nums),end(nums)); //O(nlogn) _ .O(logn)
        int x = nums.size();
        return nums[x/2];

    }
    */

    int majorityElement(vector<int>& nums){
        int count = 0;
        int candidate = 0;

        for(auto num: nums){
            if(count == 0){
                candidate = num;
            }

            if(candidate == num){
                count++;
            }else{
                count--;
            }
        }

        return candidate;
    }
};