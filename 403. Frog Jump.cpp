/*
class Solution {
public:
    bool recursion(vector<int>& stones, int index, int prevjump){
        if(index >= stones.size())
            return false;
        if(index == stones.size()-1)
            return true;
        
        bool canjump = false;
        for(int i=index+1; i<stones.size(); i++){
            int diff = stones[i]-stones[index];
            if(diff == prevjump-1 || diff == prevjump || diff == prevjump+1){
                canjump |= recursion(stones, i, diff);
            }
            if(diff > prevjump+1)
                break;
        }
        return canjump;
    }

    bool memo(vector<int>& stones, int index, int prevjump, map<pair<int,string>, int>& dp){
        if(index >= stones.size())
            return false;
        if(index == stones.size()-1)
            return true;
        
        string prev = to_string(prevjump);
        if(dp.count({index,prev}))
            return dp[{index, prev}];

        bool canjump = false;
        for(int i=index+1; i<stones.size(); i++){
            int diff = stones[i]-stones[index];
            if(diff == prevjump-1 || diff == prevjump || diff == prevjump+1){
                canjump |= memo(stones, i, diff, dp);
            }
            if(diff > prevjump+1)
                break;
        }
        return dp[{index, prev}] = canjump;
    }

    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)
            return false;

        // return recursion(stones, 1, 1);

        int n = stones.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        map<pair<int,string>, int> dp;
        return memo(stones, 1, 1, dp);
    }
};
*/

class Solution {
public:
    unordered_map<int,int> exist;
    bool recursion(vector<int>&stones, int index, int prevjump, vector<vector<int>>& dp){
        if(index >= stones.size())
            return false;
        else if(index == stones.size()-1)
            return true;
        
        if(dp[index][prevjump] != -1)
            return dp[index][prevjump];
        
        for(int jumps=prevjump-1; jumps<=prevjump+1; jumps++){
            if(jumps>0 and exist.count(stones[index] + jumps)){
                int newindex = exist[stones[index]+jumps];
                if(recursion(stones, newindex, jumps, dp))
                    return dp[index][prevjump] = true;
            }
        }
        return dp[index][prevjump] = false;
    }
    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(int i=0; i<n; i++){
            exist[stones[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return recursion(stones, 0, 0, dp);
    }
};