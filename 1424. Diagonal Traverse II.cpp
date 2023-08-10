class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        int n = nums.size();
        int m = 0;

        for(int i=0; i<n; i++){
            int loc = nums[i].size();
            m = max(m, loc);
        }

        int size = m+n-1;
        vector<vector<int>> storage(size, vector<int>());

        int start = 0;

        for(int i=0; i<n; i++){
            int ghost = start;
            for(int j=0; j<nums[i].size(); j++){
                storage[ghost++].push_back(nums[i][j]);
            }
            start++;
        }

        vector<int> money;

        for(int i=0; i<storage.size(); i++){
            for(int j=storage[i].size()-1; j>=0; j--){
                money.push_back(storage[i][j]);
            }
        }
        return money;
    }
};