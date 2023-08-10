class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1;  
        int dalal = start + (end-start)/2;
        while(start<=end){

            if(nums[dalal] == target)
                return true;
            else if(nums[start] < nums[dalal]){ // left portion
                if(nums[start] <= target and target < nums[dalal]){
                    end = dalal-1;
                }else{
                    start = dalal+1;
                }
            }else if(nums[start] > nums[dalal]){ // right portion
                if(nums[dalal] < target and target <= nums[end]){
                    start = dalal+1;
                }else{  
                    end = dalal-1;
                }
            }else{  // when starting and dalal is same? then just increase the start
                start++;
            }

            dalal = start + (end-start)/2;
        }

        return false;
    }
};