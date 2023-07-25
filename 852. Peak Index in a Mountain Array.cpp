class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0, end=arr.size()-1;
        int ans = -1;
        while(start<end){
            int mid = start + (end-start)/2;
            if(arr[mid-1] < arr[mid] and arr[mid] > arr[mid+1]){
                ans = mid;
                break;
            }else if(arr[mid-1] < arr[mid]){
                start = mid;
            }else{
                end = mid;
            }
        }

        return ans;
    }
};