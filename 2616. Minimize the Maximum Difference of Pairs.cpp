class Solution {
public:
    int valid(vector<int>& nums, int threshold, int p){

        int count=0, i=0;

        while(i<nums.size()-1){

            if(abs(nums[i]-nums[i+1]) <= threshold){
                count++;
                i += 2;
            }else{
                i++;
            }

            if(count == p)
                return true;
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if(p == 0)
            return 0;

        sort(nums.begin(), nums.end());
        
        int start=0, end=nums.back()-nums[0];
        int mid = start + (end-start)/2;
        int answer = 1e9+7;
        while(start <= end){
            if(valid(nums, mid, p)){
                answer = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }

        return answer;
    }
};