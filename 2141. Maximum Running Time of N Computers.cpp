class Solution {
public:
    typedef long long ll;
    bool possible(int n, long long mid, vector<int>& batteries){
        ll need_time = n*mid;

        for(auto& i:batteries){
            need_time -= min(mid, (ll)i);
            if(need_time <= 0)
                return true;
        }

        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll start = *min_element(begin(batteries), end(batteries));
        ll ends = accumulate(begin(batteries), end(batteries), 0LL)/n;
        ll ans = 0;

        while(start<=ends){
            ll mid = start + (ends-start)/2;
            if(possible(n, mid, batteries)){
                ans = mid;
                start = mid+1;
            }else{
                ends = mid-1;
            }
        }

        return ans;
    }
};