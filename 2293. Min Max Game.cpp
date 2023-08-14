class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        while(true){
            vector<int> temp;
            bool mini = true;
            if(nums.size() == 1)
                break;
            for(int i=0; i<nums.size(); i+=2){

                if(mini)
                    temp.push_back(min(nums[i], nums[i+1]));
                else
                    temp.push_back(max(nums[i], nums[i+1]));
                
                mini = !mini;
            }
            nums = temp;
        }
        return nums[0];
    }
};