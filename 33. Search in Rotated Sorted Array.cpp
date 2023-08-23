
class Solution {
public:
    int findpervert(vector<int>& nums){
        int start=0, end=nums.size()-1;
        int mid = start + (end-start)/2;
        while(start<end){
            
            if(0<mid and nums[mid-1] > nums[mid])
                return mid;
            else if(mid<nums.size()-1 and nums[mid]>nums[mid+1])
                return mid+1;
            else if(nums[0]>nums[mid])
                end = mid-1;
            else
                start = mid+1;
            mid = start + (end-start)/2;
        }   
        return 0;
    }

    int Binarysearch(vector<int>&nums, int start, int end, int target){

        int mid = start + (end-start)/2;

        while(start<=end){
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
            mid = start + (end-start)/2;
        }
        return -1;
    }

    int FirstSearchthenBS(vector<int>&nums ,int target){
        int pervert = findpervert(nums);
        cout << "Perver " << pervert << endl;
        int ans = -1;
    
        if(nums[pervert] <= target and target <= nums[nums.size()-1]){
            ans = Binarysearch(nums, pervert, nums.size()-1, target);
        }else{
            ans = Binarysearch(nums, 0, pervert-1, target);
        }
        
        return ans;
    }

    int search(vector<int>& nums, int target) {
        
        // return FirstSearchthenBS(nums, target);

        int start = 0, end = nums.size()-1;
        int mid = start + (end-start)/2;
        while(start<=end){

            if(nums[mid] == target)
                return mid;
            else if(nums[start] <= nums[mid]){
                if(nums[start] <= target and target < nums[mid])
                    end = mid-1;
                else
                    start = mid+1;
            }else{
                if(nums[mid] < target and target <= nums[end])
                    start = mid+1;
                else
                    end = mid-1;
            }

            mid = start + (end-start)/2;
        }

        return -1;
    }
};