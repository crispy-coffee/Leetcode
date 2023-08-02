class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Approach 1 tc-O(n^2) Sc-1;
        /*
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
        */

        // Approach 2 TC-O(n) Sc - O(n)
        unordered_map<int,int> present;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int need = target-nums[i];
            if(present.count(need)){
                return {i, present[need]};
            }
            present[nums[i]] = i;
        }

        return {};
    }
};