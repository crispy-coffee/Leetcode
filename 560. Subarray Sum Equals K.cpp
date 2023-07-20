class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {

        // Brute force (TLE)        
        /*
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++){
            long long sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum == k)
                    count++;
            }
        }
        return count;
        */

        unordered_map<int, int> present;
        present[0] = 1;
        long long prefix = 0;
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            prefix += nums[i];
            int looking_for = prefix-k;
            
            if(present.count(looking_for)){
                count += present[looking_for];
            }
            if(present.count(prefix)){
                present[prefix]++;
            }else{
                present[prefix] = 1;
            }
        }
        return count; 
    }
};