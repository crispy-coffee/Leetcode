class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
        if(k==1) return nums;

        priority_queue<pair<int,int>> q;
        vector<int> maxi;
        int i, n = nums.size();
        for(i=0; i<k; i++){
            q.push({nums[i],i});
        }

        maxi.push_back(q.top().first);

        for(i; i<n; i++){

            while(q.top().second <= i-k)
                q.pop();

            q.push({nums[i],i});

            maxi.push_back(q.top().first); 
            
        }
        return maxi;
        */

        if(k==1)
            return nums;

        vector<int> india;
        priority_queue<pair<int,int>> maxi;

        int i;
        for(i=0; i<nums.size(); i++){

            if(i<k-1)
                maxi.push({nums[i], i});
            else{
                while(maxi.top().second <= i-k)
                    maxi.pop();
                
                maxi.push({nums[i], i});

                india.push_back(maxi.top().first);
            }
        }

        return india;
    }
};
