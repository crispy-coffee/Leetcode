class Solution {
public:
    // 1 Recursion
    bool Recursion(string& s, string temp, vector<string>& dic){
        if(s.size() < temp.size())
            return false;
        
        if(s == temp)
            return true;

        for(auto i:dic){
            bool  ans = true;
            int index = temp.size();
            for(int j=0; j<i.size(); j++, index++){
                if(i[j] != s[index]){
                    ans = false;
                    break;
                }
            }
            if(ans and Recursion(s, temp+i, dic))
                return true;
            
        }
        return false;
    }

    bool Memoization(string& s, string temp, vector<string>&dic, unordered_map<string,bool>& dp){
        if(s.size() < temp.size())
            return false;
        
        if(s == temp)
            return true;

        if(dp.count(temp))
            return dp[temp];

        for(auto i:dic){
            bool  ans = true;
            int index = temp.size();
            for(int j=0; j<i.size(); j++, index++){
                if(i[j] != s[index]){
                    ans = false;
                    break;
                }
            }
            if(ans and Memoization(s, temp+i, dic, dp))
                return dp[temp] = true;
            
        }

        return dp[temp] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        // 1 Recursion
        // return Recursion(s, "", wordDict);

        unordered_map<string,bool> dp;
        return Memoization(s,"", wordDict, dp);
    }
};