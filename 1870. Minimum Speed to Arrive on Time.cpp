class Solution {
public:
    bool check(vector<int>& dist, int speed, double hour){
        int i=0;
        double time = 0;
        for(; i<dist.size()-1; i++){
            time += ceil((double)dist[i]/speed);
        }
        time += (double)dist[i]/speed;
        return time<=hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int start = 1, end = 10000000; //Range of speed
        
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;

            if(check(dist, mid, hour)){ //Check if possible
                ans = mid;
                end = mid-1; //if possible then we need to find "minimum speed"
            }else{
                start = mid+1; 
            }
        }

        return ans;
    }
};