#include<algorithm>

class Solution {
public:
    double average(vector<int>& salary) {
        double total = 0, mini = INT_MAX, maxi = INT_MIN;
        for(auto i:salary){
            total += i;
            mini = mini > i ? i:mini;
            maxi = maxi < i ? i:maxi;
        }

        total -= (mini + maxi);
        return total/(salary.size()-2);
    }
};