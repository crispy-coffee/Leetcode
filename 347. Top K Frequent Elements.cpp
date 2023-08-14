class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        priority_queue<pair<int,int>> p;
        int count = 1;
        int n = nums.size();
        int i = 1;
        for(i = 1; i<n; i++){
            if(nums[i] == nums[i-1]){
                count++;
            }else{
                p.push({count,nums[i-1]});
                count = 1;
            }
        }
        p.push({count,nums[i-1]});
        vector<int> ans;
        while(!p.empty() and k--){
            ans.push_back(p.top().second);
            p.pop();
        }

        return ans;
    }
};