class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> startEnd(n+1,0);

        for(int i=0; i<=n; i++){
            int start = max(0, i-ranges[i]);
            int end   = min(n, i+ranges[i]);
            
            startEnd[start] = max(startEnd[start], end);
        }

        int taps     = 0;
        int farthest = 0;
        int current  = 0;

        for(int i=0; i<=n; i++){
            
            if(i > farthest)
                return -1;

            if(i > current){
                current = farthest;
                taps++;
            }
            
            farthest = max(farthest, startEnd[i]);
        }

        return taps;
    }   
};