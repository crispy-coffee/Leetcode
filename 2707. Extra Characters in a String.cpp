class Solution {
public:
    int n;
    int r(string& s, int index, unordered_map<string,bool>& str){
        if(index == n)
            return 0;
        
        string currstring = "";
        int minExtra = n;
        for(int i=index; i<n; i++){
            currstring.push_back(s[i]);
            int currExtra = 0;
            if(!str.count(currstring)){
                currExtra = currstring.size();
            }

            int remainingExtra = r(s, i+1, str);
            minExtra = min(minExtra, currExtra + remainingExtra);
        }

        return minExtra;
    }

    vector<int> dp;
    int m(string& s, int index, unordered_map<string,bool>& str){
        if(index == n)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];

        string currstring = "";
        int minExtra = n;
        for(int i=index; i<n; i++){
            currstring.push_back(s[i]);
            int currExtra = 0;
            if(!str.count(currstring)){
                currExtra = currstring.size();
            }

            int remainingExtra = m(s, i+1, str);
            minExtra = min(minExtra, currExtra + remainingExtra);
        }

        return dp[index] = minExtra;
    }

    int t(string& s, unordered_map<string,bool>& str){
        dp[n] = 0;

        for(int index=n-1; index>=0; index--){
            string currstring = "";
            int minExtra = n;
            for(int i=index; i<n; i++){
                currstring.push_back(s[i]);
                int currExtra = 0;

                if(!str.count(currstring)){
                    currExtra = currstring.size();
                }
                
                int remainingExtra = dp[i+1];
                minExtra = min(minExtra, currExtra + remainingExtra);
            }

            dp[index] = minExtra;
        }
        return dp[0];
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        unordered_map<string,bool> str;
        for(auto i:dictionary){
            str[i] = true;
        }

        // Recursion
        // return r(s, 0, str);

        // Memoization
        dp.resize(n+1, -1);
        // return m(s, 0, str);

        // Tabulation
        return t(s, str);

    }
};