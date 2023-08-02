class Solution {
public:
    void sortColors(vector<int>& nums) {
        //   Write your code here
        // There is 3 way to solve
        // 1 using Sort
        // sort(nums.begin(), nums.end());

        // 2 By Count
        /*
        int zero = 0, one = 0, two = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0)
                zero++;
            else if(nums[i] == 1)
                one++;
            else
                two++;
        }
        int index = 0;
        while(zero--){
            nums[index] = 0;
            index++;\
        }

        while(one--){
            nums[index] = 1;
            index++;
        }

        while(two--){
            nums[index] = 2;
            index++;
        }
        */

        // 3 By inplace change
        int zero=0, one=0, two=nums.size()-1;

        while(one<=two){

            if(nums[one] == 0){
                swap(nums[zero++], nums[one++]);
            }else if(nums[one] == 1){
                one++;
            }else if(nums[one] == 2){
                swap(nums[one], nums[two--]);
            }
        }
    }
};